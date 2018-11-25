#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <math.h>

using namespace cv;
using namespace std;

bool limiar(int media,int valor){
	int T = (media - pow(media - valor,2));
	return valor <= media;
} 

int main( int argc, char** argv )
{
// char* imageName = "Treino/lvl1/lvl1-2.png";

 Mat image;
 image = imread( "lvl2-4.png", 1 );

 Mat gray_image,mediana,final;
 cvtColor( image, gray_image, CV_BGR2GRAY );

 medianBlur(gray_image,mediana,3);//FILTRO PASSA BAIXA
 final = mediana.clone(); //CLONAGEM DA IMAGEM PASSADA A MEDIA

 int largura = mediana.size().width;
 int altura = mediana.size().height;
 int i,j;
 int valorMedio;
 int Media = 0; 
 for(i=0;i<altura;i++){
 	
 	for(j=0;j<largura;j++){
 		Media+=(int)mediana.at<Vec3b>(i, j).val[0];
 		Media+=(int)mediana.at<Vec3b>(i, j).val[1];
 		Media+=(int)mediana.at<Vec3b>(i, j).val[2];
 	}
 } 
 Media = Media/ (largura*altura);
 Media/=3;
 printf("Valor medio da img = %d\n",Media );

 threshold( mediana, final, Media,255,0);

 

 imwrite( "final.png", final);
  
 return 0;
}