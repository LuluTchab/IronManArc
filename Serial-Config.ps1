param([int]$portNo)

$PROMPT_TYPE_STRING = ">"
$PROMPT_TYPE_DIGIT = "#"
$PROMPT_TYPE_YES_NO = "&"
$PROMPT_TYPE_PASSWORD = "\*"

$PROMPT_TYPE_LIST = @(
    $PROMPT_TYPE_STRING,
    $PROMPT_TYPE_DIGIT,
    $PROMPT_TYPE_YES_NO,
    $PROMPT_TYPE_PASSWORD
)
$INPUT_PATTERN_MATCH = ":?[{0}]$" -f ($PROMPT_TYPE_LIST -join "")

# If no port has been given as parameter
if($portNo -eq 0)
{
    Write-Host "No COM port number has been given as argument, please select one of the following:"

    $portNoList = @([System.IO.Ports.SerialPort]::getportnames() | ForEach-Object { $_ -replace "COM",""})

    do # Asking for COM port no as long as a correct one has not been given
    {
        ForEach($comPortNo in $portNoList)
        {
            Write-Host ("[{0}] COM{0}" -f $comPortNo )
        }
        $portNo = Read-Host "Enter port no"
        if($portNo -notin $portNoList)
        {
            $portNo = 0
        }
    }
    while($portNo -eq 0)
    
}

Write-Host "Opening COM port..."

$portObj = new-Object System.IO.Ports.SerialPort ("COM{0}" -f $portNo),115200,None,8,one

# We close port in case it was left opened
$portObj.Close()
$portObj.open()

# Sending request for menu to Arc reactor
$portObj.WriteLine("?")
Start-Sleep -Milliseconds 50

# Reading lines in buffer (including lines returned because of the previous 'WriteLine()' )
do
{
    $line = $portObj.ReadLine() -replace "`n","" -replace "`r",""
    Start-Sleep -Milliseconds 50
}
while($line -notmatch '^Choice')


# Sending request for menu to Arc reactor
$portObj.WriteLine("?")
Start-Sleep -Milliseconds 50

while($true)
{
    # Reading next line sent by Arc Reactor and remove 'new lines' characters
    $line = $portObj.ReadLine() -replace "`n","" -replace "`r",""

    # If line matches an input pattern
    if($line -match $INPUT_PATTERN_MATCH)
    {
        Write-Host "" # Just a new line
        # Removing prompt type from string sent from Arc Reactor
        $prompt = $line -replace $INPUT_PATTERN_MATCH,""
        if($prompt -eq "")
        {
            $prompt = " "
        }
        # Creating command line to read user input
        $cmdLine = '$cmd = Read-Host $prompt'
        $secureInput = ($line -match ('{0}$' -f $PROMPT_TYPE_PASSWORD))
        if($secureInput)
        {
            $cmdLine = "{0} -AsSecureString" -f $cmdLine
        }

        do # Asking for user input
        {
            Invoke-Expression $cmdLine

            if($secureInput)
            {
                # Transform it back to human readable text
                $cmd = [Runtime.InteropServices.Marshal]::PtrToStringAuto([Runtime.InteropServices.Marshal]::SecureStringToBSTR($cmd))
            }
            else
            {
                $cmd = $cmd.Trim()
            }
        
            if($cmd -ne "")
            {
                try
                {
                    # If digit/number is expected and user didn't entered this
                    if(($line -match ('{0}$' -f $PROMPT_TYPE_DIGIT)) -and ($cmd -notmatch '^\d+$'))
                    {
                        Throw "Number expected"
                    }
                    # If 'y'|'n' expected and user didn't entered this
                    elseif(($line -match ('{0}$' -f $PROMPT_TYPE_YES_NO)) -and ($cmd.ToLower() -notmatch '^(y|n)$'))
                    {
                        Throw "'y' or 'n' expected"
                    }

                    # If we arrive here, it means everything is OK to send user input back to Arc Reactor
                    $portObj.WriteLine($cmd)
                    Start-Sleep -Milliseconds 50
                }
                catch
                {
                    Write-Warning $_.exception.message
                    $cmd = ""
                }
            }
        }
        while($cmd -eq "") # keep asking as long as input is not correct
        
    }
    else # Line doesn't matches an input patern, 
    {
        # Just displaying it
        Write-host $line -ForegroundColor:Cyan        
    }
}

# In fact we'll never reach this line because of the infinite loop but still... it is here XD
$portObj.Close()