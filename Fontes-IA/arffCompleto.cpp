#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <math.h>

using namespace cv;
using namespace std;

bool isBlu(Vec3b RGB)
{
	uchar azul = RGB.val[0];
	uchar verde = RGB.val[1];
	uchar vermelho = RGB.val[2];


	return ((int)azul>150 and (int)vermelho<40 and (int)verde<40);	
}

bool isGreen(Vec3b RGB)
{
  uchar azul = RGB.val[0];
  uchar verde = RGB.val[1];
  uchar vermelho = RGB.val[2];


  return ((int)azul<40 and (int)vermelho<40 and (int)verde>150);  
}

bool islesao(Vec3b RGB)
{
    uchar azul = RGB.val[0];
    uchar verde = RGB.val[1];
    uchar vermelho = RGB.val[2];

    return ((uchar)((azul + verde + vermelho) / 3))<227; 
}

bool isBlack(Vec3b RGB)
{
	uchar azul = RGB.val[0];
	uchar verde = RGB.val[1];
	uchar vermelho = RGB.val[2];


	return ((int)azul<40 and (int)vermelho<40 and (int)verde<40);
}

int main()
{
    
    FILE *Arff;
    Arff = fopen("lesaos.arff","w");

    fprintf(Arff,"@RELATION lesao\n@ATTRIBUTE R REAL\n@ATTRIBUTE G REAL\n@ATTRIBUTE B REAL\n@ATTRIBUTE L REAL\n@ATTRIBUTE a REAL\n@ATTRIBUTE b REAL\n@ATTRIBUTE H REAL\n@ATTRIBUTE S REAL\n@ATTRIBUTE V REAL\n@ATTRIBUTE B-G REAL\n@ATTRIBUTE B-R REAL\n@ATTRIBUTE G-R REAL\n@ATTRIBUTE class  {patogenico,normal}\n\n@DATA\n");

    Mat imgNatural; 
    Mat imgPintada;
    
    Mat imgLab,imgHsv,RedOne;

    int largura;
    int altura;

    int totallesao = 0, total = 0,totalPatogenico = 0;

    
    Vec3b pixelRGB;
    Vec3b pixelLab;
    Vec3b pixelHSV;
    
    string nomeEntrada;
    string nomeEntradaPintado;
    string nomeSaida;
    int x, y,numlesaos;
    for(numlesaos=0;numlesaos<5;numlesaos++)
    {
      
      if(numlesaos==0){
        nomeEntrada = "Treino/lvl1/lvl1-2.png";
        nomeEntradaPintado = "Treino/lvl1/lvl1-2SEG.png";
        nomeSaida = "lvl1-2SEG-s.png";
      }
      if(numlesaos==1){
        nomeEntrada = "Treino/lvl1/lvl1-3.png";
        nomeEntradaPintado = "Treino/lvl1/lvl1-3SEG.png";
        nomeSaida = "lvl1-3SEG-s.png";
      }
      if(numlesaos==2){
        nomeEntrada = "Treino/lvl2/lvl2-2.png";
        nomeEntradaPintado = "Treino/lvl2/lvl2-2SEG.png";
        nomeSaida = "lvl2-2SEG-s.png";
      }
      if(numlesaos==3){
        nomeEntrada = "Treino/lvl2/lvl2-4.png";
        nomeEntradaPintado = "Treino/lvl2/lvl2-4SEG.png";
        nomeSaida = "lvl2-4SEG-s.png";
      }
      if(numlesaos==4){
        nomeEntrada = "Treino/lvl2/lvl2-1.png";
        nomeEntradaPintado = "Treino/lvl2/lvl2-1SEG.png";
        nomeSaida = "lvl2-1SEG-s.png";
      }
      

      imgNatural = imread(nomeEntrada); 
      imgPintada = imread(nomeEntradaPintado);

      RedOne = imgPintada.clone();

      cvtColor(imgNatural,imgLab,COLOR_BGR2Lab);//Cria uma copia da imagem Natural usando LAB
      cvtColor(imgNatural,imgHsv,COLOR_BGR2HSV);//Cria uma copia da imagem Natural usando HSV

      largura = imgNatural.size().width;
      altura = imgNatural.size().height;
      int diminuidor = 1;
      for(x = 0; x < altura; x++)
      {
          for(y = 0; y < largura; y++)
          {
              if(1)//Verifica se o pixel atual faz parte da regiao
              {

                pixelRGB = imgNatural.at<Vec3b>(x, y); //Pixel RGB
                pixelLab = imgLab.at<Vec3b>(x, y);     //Pixel LAB
                pixelHSV = imgHsv.at<Vec3b>(x, y);     //Pixel HSV

                if(isBlack(imgPintada.at<Vec3b>(x, y)))//Caso seja ponto preto (patogenico)
                {
                  if(diminuidor<2){
                    RedOne.at<Vec3b>(x,y) = (Vec3b){0,0,225};
                    
                    //ESCREVENDO NO ARQUIVO OS DADOS
                    fprintf(Arff,"%.2f,%.2f,%.2f",(float)pixelRGB.val[2],(float)pixelRGB.val[1],(float)pixelRGB.val[0]);//RGB
                    fprintf(Arff,",%.2f,%.2f,%.2f",(float)pixelLab.val[0],(float)pixelLab.val[1],(float)pixelLab.val[2]);//LAB
                    fprintf(Arff,",%.2f,%.2f,%.2f",(float)pixelHSV.val[0],(float)pixelHSV.val[1],(float)pixelHSV.val[2]);//HSV
                    //fprintf(Arff,",%.2f,%.2f,%.2f",(float)pixelHSI.val[0],(float)pixelHSI.val[1],(float)pixelHSI.val[2]);//HSI
                    fprintf(Arff, ",%.2f",(float)abs((float)pixelRGB.val[0]-(float)pixelRGB.val[1]) );//B-G
                    fprintf(Arff, ",%.2f",(float)abs((float)pixelRGB.val[0]-(float)pixelRGB.val[2]) );//B-R
                    fprintf(Arff, ",%.2f",(float)abs((float)pixelRGB.val[1]-(float)pixelRGB.val[2]) );//G-R  
                    fprintf(Arff, ",lvl1\n");
                  
                    totalPatogenico++;   
                  }else{
                    if(diminuidor == 3)
                        diminuidor = 0;
                  }
                  diminuidor++;
                  
                }else//Se nao  (natural)
                {               
                  if(isBlu(imgPintada.at<Vec3b>(x, y)))
                  {
                    RedOne.at<Vec3b>(x,y) = (Vec3b){0,255,0};
                    //ESCREVENDO NO ARQUIVO OS DADOS
                    fprintf(Arff,"%.2f,%.2f,%.2f",(float)pixelRGB.val[2],(float)pixelRGB.val[1],(float)pixelRGB.val[0]);//RGB
                    fprintf(Arff,",%.2f,%.2f,%.2f",(float)pixelLab.val[0],(float)pixelLab.val[1],(float)pixelLab.val[2]);//LAB
                    fprintf(Arff,",%.2f,%.2f,%.2f",(float)pixelHSV.val[0],(float)pixelHSV.val[1],(float)pixelHSV.val[2]);//HSV
                    //fprintf(Arff,",%.2f,%.2f,%.2f",(float)pixelHSI.val[0],(float)pixelHSI.val[1],(float)pixelHSI.val[2]);//HSI
                    fprintf(Arff, ",%.2f",(float)abs((float)pixelRGB.val[0]-(float)pixelRGB.val[1]) );//B-G
                    fprintf(Arff, ",%.2f",(float)abs((float)pixelRGB.val[0]-(float)pixelRGB.val[2]) );//B-R
                    fprintf(Arff, ",%.2f",(float)abs((float)pixelRGB.val[1]-(float)pixelRGB.val[2]) );//G-R  
                    fprintf(Arff, ",lvl2\n");
                    totallesao++;
                  }
                }
                total++;
              }
          }
      }
      imwrite(nomeSaida,RedOne);
    }
    fclose(Arff);
    printf("Total lvl1 = %d\n",totalPatogenico);
    printf("Total lvl2 = %d\n",totallesao);
}
