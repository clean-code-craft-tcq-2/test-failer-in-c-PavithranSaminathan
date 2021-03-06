#include <stdio.h>
#include <assert.h>

#define THRESHOLD_VALUE 300

int alertFailureCount = 0;
int Test_alertFailureCount=0;

#define     Test            0u
#define     PRODUCTION      1U

#define     ENVIRONMENT     0U

//Stub function for Network Alert in AlertInCelcius_Test testcase
int NetworkAlertStub_NOK(float celcius)
{
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);   
    return 500;    
}

int NetworkAlertStub_OK(float celcius)
{
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);   
    return 200;    
}

//Real network aleter function for alertInCelcius
//This function will return error status based on threshold
int NetworkAlert(float celcius)
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

//This function will convert farenheit to celcius and test the alert
void alertInCelcius(float farenheit, int (*NetWorkAlert_FunP)(float celcius))
{
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = NetWorkAlert_FunP(celcius);
    if (returnCode != 200)
    {
        alertFailureCount += 1;
    }
}

int main() 
{
    
    int (*NetWorkAlert_FunP[3])(float celcius) ={NetworkAlert,NetworkAlertStub_OK,NetworkAlertStub_NOK};
    
    #if (ENVIRONMENT == PRODUCTION)
    
    alertInCelcius(400.5,NetWorkAlert_FunP[0]);
    alertInCelcius(303.6,NetWorkAlert_FunP[0]);
    
    #elif (ENVIRONMENT == TEST)
    
    alertInCelcius(400.5,NetWorkAlert_FunP[1]);
    alertInCelcius(303.6,NetWorkAlert_FunP[1]);
    
    assert(alertFailureCount == 0);
    
    alertInCelcius(400.5,NetWorkAlert_FunP[2]);
    alertInCelcius(303.6,NetWorkAlert_FunP[2]);
    
    assert(alertFailureCount == 2);
    
    #endif
    
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
