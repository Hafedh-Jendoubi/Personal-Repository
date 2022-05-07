#include <stdio.h>

int main()
{
    float Total, Total_remise, remise;

    printf("Taper le total a payer: "); scanf("%f", &Total);
    if(Total<20)
        remise = 1;
    else if(Total<100)
        remise = 0.95;
    else if(Total<200)
        remise = 0.9;
    else
        remise = 0.85;
    Total_remise = Total*remise;
    printf("Le montant a payer est %.2f\n", Total_remise);

    return 0;
}
