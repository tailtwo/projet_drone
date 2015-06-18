#include <stdio.h>
#include <RT_ARDrone/RT_ARDrone.h>
//#include "glwindow.h"

float calculangle (float a, float b)
	{
	float c;
		if (b < 0 && b < 90){
			b=-b;
		 }
		 if (a < 0 && a < 90){
			a=-a;
		 }
	
		 
	if ((b < 0 && a > 0)||(b > 0 && a < 0))
	{
		c = abs((a + b) - 360);
	}
	else
	{
		c=abs(b-a);
	} 
	return c;
}

int main ( int argc, char** argv, char** envv ) {

	int i ;
	ARDrone* bob ;
	NavData  data ;
	float initangle;
	float newangle;
	//VideoStream* test;
	//RGB24Image* img;
	//GLWindow* win;
	
	//img=RGB24Image_new(640,360);
	

	bob = ARDrone_new( "192.168.1.1" ) ;

	ARDrone_connect( bob ) ;
	
	//test = VideoStream_new ("192.168.1.1");

	
	/*VideoStream_connect ( test ); 
	
	/VideoStream_getRGB24Image (test , img);
	
	GLwindow_draw_rgb(win,img->pixels);
	
	GLWindow_swap_buffers(win);*/
		
	ARDrone_trim ( bob ) ;
	
	sleep(5) ;
	
	ARDrone_takeoff( bob ) ;
	
	initangle = data.psi ;
ARDrone_move( bob, 0, 0 , 0, 0, 0) ;
      sleep(4);
   sleep(4);
   
      while (calculangle(initangle,newangle) < 90){
	  newangle = data.psi;
	  printf("%f %f\n",initangle,newangle);
      ARDrone_move( bob, 0, 0 , 0, 0.2, 0) ;
      sleep(3);
      //ARDrone_move( bob, 0, 0 , 0, 0.38, 0) ;
      //sleep(2);
	}
      ARDrone_move( bob, 0, 0 , 0, 0, 0) ;
      sleep(3);
       printf( "Avance de 5 mètres \n") ;
    
//float pitch=-0.2; 
  
   ARDrone_move( bob, 1, 0 , -0.15, 0, 0) ; 
    ARDrone_get_navdata( bob, &data ) ;

    sleep(4); 
    
     ARDrone_move( bob, 0, 0 , 0, 0, 0) ;
     ARDrone_get_navdata( bob, &data ) ; 
sleep(2);
      printf( "gps %f", data.psi) ;
      printf("%f %f\n",initangle,newangle);
      
      initangle = data.psi ;
      
      while (calculangle(initangle,newangle) < 90){
	  newangle = data.psi;
	  printf("%f %f\n",initangle,newangle);
      ARDrone_move( bob, 0, 0 , 0, 0.2, 0) ;
      sleep(3);
      //ARDrone_move( bob, 0, 0 , 0, 0.38, 0) ;
      //sleep(2);
	}
	
    sleep(2);
    printf("%f %f\n",initangle,newangle);
    ARDrone_move( bob, 0, 0 , 0, 0, 0) ;
	sleep(1);
	
   ARDrone_land( bob );
    sleep(2);
	
	
	for ( i=0; i<2; i++ ) {

		sleep(1) ;
		ARDrone_get_navdata( bob, &data ) ;
		printf( "state %d - bat %d \n", data.state, data.bat ) ;
		
	}

	
	ARDrone_free( bob ) ;


	return 0 ;

}
