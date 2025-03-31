Set-Location build
cmake ..

# Run mingw32-make and check if it succeeds
mingw32-make
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error in the building process." -ForegroundColor Red
    exit $LASTEXITCODE
}

# If no error, run the executable
.\NeuralNetwork
