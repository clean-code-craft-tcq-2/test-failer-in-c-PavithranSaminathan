#include <stdio.h>
#include <assert.h>

#define THRESHOLD_VALUE 300

int alertFailureCount = 0;
int Test_alertFailureCount=0;

int NetworkAlertStub(float celcius)
{
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if(THRESHOLD_VALUE > celcius)
    {
        return 500;
    }
    else
    {
        return 200;
    }
}

void AlertInCelcius_Test(float farenheit)
{
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = NetworkAlertStub(celcius);
    if (returnCode != 200)
    {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        Test_alertFailureCount += 0;
    }
}

int networkAlert(float celcius)
{
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if(THRESHOLD_VALUE > celcius)
    {
        return 200;
    }
    else
    {
        return 500;    
    }    
}

void alertInCelcius(float farenheit)
{
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200)
    {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    AlertInCelcius_Test(400.5);
    AlertInCelcius_Test(303.6);
    assert(Test_alertFailureCount != 0);
    printf("%d alerts failed.\n", Test_alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
