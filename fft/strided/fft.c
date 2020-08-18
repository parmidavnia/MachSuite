#include "fft.h"
#include "stdio.h"
void fft(double real[FFT_SIZE], double img[FFT_SIZE], double real_twid[FFT_SIZE/2], double img_twid[FFT_SIZE/2]){
    int even, odd, span, log, rootindex;
    double temp;
    log = 0;

    outer:for(span=FFT_SIZE>>1; span; span>>=1, log++){
        inner:for(odd=span; odd<FFT_SIZE; odd++){
            odd |= span;
            even = odd ^ span;	    


            temp = real[even] + real[odd];
	    //printf("%lf\n", temp);
            real[odd] = real[even] - real[odd];
            real[even] = temp;
	   // printf("odd real[%d]=%lf, even real[%d]=%lf\n",odd,real[odd],even,real[even]);
           // printf("%lf,%d,%lf,%d\n",real[odd],odd,real[even],even);
	   
		//temp2
	    temp = img[even] + img[odd];
	    //printf("temp,odd,even\n");
	    //printf("temp[%lf][%d]=%d\n", temp,odd,even);

            img[odd] = img[even] - img[odd];
            img[even] = temp;
	    //printf("img[odd]\n");
	    //printf("%lf[%d]\n",img[odd],odd);
             
            rootindex = (even<<log) & (FFT_SIZE - 1);
	    //printf("rootindex,odd,even\n");            
	    //printf("%lf, %d, %d \n",rootindex, odd, even);
	    if(rootindex){
		//temp3
                temp = real_twid[rootindex] * real[odd] - img_twid[rootindex]  * img[odd];
		//printf("temp3,rootindex,odd,even\n");
		//printf("%lf, %d, %d, %d\n",temp,rootindex,odd,even);	
                img[odd] = real_twid[rootindex]*img[odd] + img_twid[rootindex]*real[odd];
		printf("img2,rootindex,odd,even\n");
                printf("%lf, %d, %d, %d\n",img[odd],rootindex,odd,even);

                real[odd] = temp;
            }
        }
    }
}
