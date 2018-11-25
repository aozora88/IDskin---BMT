#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <math.h>
#include <time.h>

using namespace cv;


//Vec3b lvl24[3] = {(Vec3b){(uchar)73,(uchar)138,(uchar)158},(Vec3b){(uchar)27,(uchar)131,(uchar)144},(Vec3b){(uchar)80,(uchar)131,(uchar)156}};
Vec3b lvl24 = (Vec3b){(uchar)73,(uchar)138,(uchar)158};

bool isMasc(Vec3b RGB)//Retorna verdadeiro se proximo de preto
{
    uchar azul = RGB.val[0];
    uchar verde = RGB.val[1];
    uchar vermelho = RGB.val[2];

    return ((uchar)((azul + verde + vermelho) / 3))<50; 
}


bool semelhante(Vec3b p, Vec3b c,double semelhanca)
{
	uchar azulP = p.val[0];
    uchar verdeP = p.val[1];
    uchar vermelhoP = p.val[2];

    uchar azulC = c.val[0];
    uchar verdeC = c.val[1];
    uchar vermelhoC = c.val[2];	

    double d = sqrt(pow((double)verdeP - (double)verdeC,2.0)+pow((double)vermelhoP - (double)vermelhoC,2.0));//+pow((double)azulP - (double)azulC,2.0)

    return d <= semelhanca;
}

bool Tree(int B,int G,int R,int L,int a,int b,int H,int S,int V,int B_R,int B_G,int G_R){
	if(B <= 73){
	    if(a <= 146){
	        return false;
	    }else{
	        if(B <= 68){
	            if(S <= 172){
	                if(R <= 127){
	                    if(b <= 142){
	                        if(H <= 178){
	                            if(B-R <= 70){
	                               return true;
	                            }else{
	                                return false;
	                            }

	                        }else{
	                            return false;
	                        }

	                    }else{
	                        if(R <= 125){
	                           return true;
	                        }else{
	                            if(R <= 126){
	                                return false;
	                            }else{
	                               return true;
	                            }
	                        }
	                    }

	                }else{
	                    if(b <= 144){
	                        if(G <= 53){
	                            if(B-G <= 15){
	                               return true;
	                            }else{
	                                if(L <= 95){
	                                   return true;
	                                }else{
	                                    return false;
	                                }
	                            }

	                        }else{
	                            if(B <= 61){
	                                if(G <= 55){
	                                   return true;
	                                }else{
	                                    return false;
	                                }

	                            }else{
	                                if(B <= 64){
	                                    if(L <= 90){
	                                        if(G <= 55){
	                                           return true;
	                                        }else{
	                                            return false;
	                                        }

	                                    }else{
	                                        return false;
	                                    }

	                                }else{
	                                   return true;
	                                }
	                            }
	                        }

	                    }else{
	                       return true;
	                    }
	                }

	            }else{
	               return true;
	            }

	        }else{
	            if(G-R <= 119){
	                if(B-G <= 18){
	                    if(G <= 77){
	                        if(B-R <= 67){
	                            if(b <= 138){
	                                return false;
	                            }else{
	                               return true;
	                            }

	                        }else{
	                            if(B <= 70){
	                                if(L <= 99){
	                                    if(R <= 157){
	                                       return true;
	                                    }else{
	                                        return false;
	                                    }

	                                }else{
	                                   return true;
	                                }

	                            }else{
	                                if(S <= 145){
	                                    if(b <= 143){
	                                        if(B <= 71){
	                                            if(b <= 142){
	                                                if(b <= 141){
	                                                    return false;
	                                                }else{
	                                                   return true;
	                                                }

	                                            }else{
	                                                return false;
	                                            }

	                                        }else{
	                                            if(H <= 0){
	                                                return false;
	                                            }else{
	                                                if(G <= 68){
	                                                    if(G <= 64){
	                                                        return false;
	                                                    }else{
	                                                        if(S <= 143){
	                                                            if(B-R <= 75){
	                                                               return true;
	                                                            }else{
	                                                                return false;
	                                                            }

	                                                        }else{
	                                                           return true;
	                                                        }
	                                                    }

	                                                }else{
	                                                   return true;
	                                                }
	                                            }
	                                        }

	                                    }else{
	                                       return true;
	                                    }

	                                }else{
	                                    if(G-R <= 116){
	                                        if(G <= 68){
	                                            if(B-R <= 105){
	                                                if(G <= 56){
	                                                    if(B-R <= 95){
	                                                        if(L <= 97){
	                                                           return true;
	                                                        }else{
	                                                            return false;
	                                                        }

	                                                    }else{
	                                                       return true;
	                                                    }

	                                                }else{
	                                                    if(H <= 177){
	                                                        if(L <= 105){
	                                                           return true;
	                                                        }else{
	                                                            if(H <= 176){
	                                                                if(a <= 174){
	                                                                    return false;
	                                                                }else{
	                                                                   return true;
	                                                                }

	                                                            }else{
	                                                                if(b <= 146){
	                                                                    if(R <= 167){
	                                                                       return true;
	                                                                    }else{
	                                                                        if(B <= 71){
	                                                                           return true;
	                                                                        }else{
	                                                                            return false;
	                                                                        }
	                                                                    }

	                                                                }else{
	                                                                   return true;
	                                                                }
	                                                            }
	                                                        }

	                                                    }else{
	                                                        if(B-R <= 89){
	                                                            if(a <= 167){
	                                                               return true;
	                                                            }else{
	                                                                return false;
	                                                            }

	                                                        }else{
	                                                           return true;
	                                                        }
	                                                    }
	                                                }

	                                            }else{
	                                                if(H <= 178){
	                                                    if(B-R <= 107){
	                                                        return false;
	                                                    }else{
	                                                       return true;
	                                                    }

	                                                }else{
	                                                    if(B <= 71){
	                                                       return true;
	                                                    }else{
	                                                        return false;
	                                                    }
	                                                }
	                                            }

	                                        }else{
	                                            if(b <= 150){
	                                                if(B <= 71){
	                                                    if(G <= 71){
	                                                        return false;
	                                                    }else{
	                                                       return true;
	                                                    }

	                                                }else{
	                                                    if(L <= 109){
	                                                       return true;
	                                                    }else{
	                                                        return false;
	                                                    }
	                                                }

	                                            }else{
	                                               return true;
	                                            }
	                                        }

	                                    }else{
	                                       return true;
	                                    }
	                                }
	                            }
	                        }

	                    }else{
	                       return true;
	                    }

	                }else{
	                    if(b <= 142){
	                        return false;
	                    }else{
	                        if(G <= 50){
	                            return false;
	                        }else{
	                           return true;
	                        }
	                    }
	                }

	            }else{
	               return true;
	            }
	        }
	    }

	}else{
	    if(B-G <= 12){
	        if(R <= 190){
	            if(G <= 77){
	                if(a <= 176){
	                    if(G-R <= 71){
	                        if(b <= 138){
	                            return false;
	                        }else{
	                            if(S <= 121){
	                                return false;
	                            }else{
	                                if(b <= 139){
	                                   return true;
	                                }else{
	                                    return false;
	                                }
	                            }
	                        }

	                    }else{
	                        if(a <= 175){
	                            if(B <= 75){
	                                if(R <= 167){
	                                    if(R <= 164){
	                                        if(L <= 106){
	                                            if(B <= 74){
	                                                if(b <= 142){
	                                                   return true;
	                                                }else{
	                                                    if(b <= 143){
	                                                        if(H <= 176){
	                                                           return true;
	                                                        }else{
	                                                            return false;
	                                                        }

	                                                    }else{
	                                                        if(L <= 105){
	                                                           return true;
	                                                        }else{
	                                                            if(H <= 177){
	                                                                return false;
	                                                            }else{
	                                                               return true;
	                                                            }
	                                                        }
	                                                    }
	                                                }

	                                            }else{
	                                                if(G-R <= 84){
	                                                    return false;
	                                                }else{
	                                                    if(H <= 176){
	                                                        if(L <= 102){
	                                                           return true;
	                                                        }else{
	                                                            if(S <= 155){
	                                                                return false;
	                                                            }else{
	                                                               return true;
	                                                            }
	                                                        }

	                                                    }else{
	                                                        if(R <= 156){
	                                                            if(a <= 165){
	                                                               return true;
	                                                            }else{
	                                                                return false;
	                                                            }

	                                                        }else{
	                                                           return true;
	                                                        }
	                                                    }
	                                                }
	                                            }

	                                        }else{
	                                           return true;
	                                        }

	                                    }else{
	                                       return true;
	                                    }

	                                }else{
	                                    if(H <= 177){
	                                        if(b <= 150){
	                                            return false;
	                                        }else{
	                                            if(G <= 76){
	                                               return true;
	                                            }else{
	                                                return false;
	                                            }
	                                        }

	                                    }else{
	                                        if(B-G <= 6){
	                                            if(L <= 116){
	                                                return false;
	                                            }else{
	                                                if(R <= 185){
	                                                   return true;
	                                                }else{
	                                                    return false;
	                                                }
	                                            }

	                                        }else{
	                                            if(b <= 148){
	                                               return true;
	                                            }else{
	                                                return false;
	                                            }
	                                        }
	                                    }
	                                }

	                            }else{
	                                if(B-R <= 91){
	                                    if(H <= 176){
	                                        return false;
	                                    }else{
	                                        if(G <= 72){
	                                            if(S <= 132){
	                                                return false;
	                                            }else{
	                                                if(L <= 111){
	                                                    if(B-G <= 9){
	                                                        if(H <= 177){
	                                                            if(L <= 101){
	                                                                return false;
	                                                            }else{
	                                                               return true;
	                                                            }

	                                                        }else{
	                                                            if(G <= 69){
	                                                                return false;
	                                                            }else{
	                                                                if(a <= 168){
	                                                                   return true;
	                                                                }else{
	                                                                    return false;
	                                                                }
	                                                            }
	                                                        }

	                                                    }else{
	                                                        if(a <= 166){
	                                                            return false;
	                                                        }else{
	                                                            if(S <= 147){
	                                                               return true;
	                                                            }else{
	                                                                if(b <= 141){
	                                                                    return false;
	                                                                }else{
	                                                                    if(L <= 104){
	                                                                       return true;
	                                                                    }else{
	                                                                        if(G-R <= 95){
	                                                                            return false;
	                                                                        }else{
	                                                                            if(b <= 142){
	                                                                               return true;
	                                                                            }else{
	                                                                                if(S <= 153){
	                                                                                    return false;
	                                                                                }else{
	                                                                                   return true;
	                                                                                }
	                                                                            }
	                                                                        }
	                                                                    }
	                                                                }
	                                                            }
	                                                        }
	                                                    }

	                                                }else{
	                                                    return false;
	                                                }
	                                            }

	                                        }else{
	                                            if(L <= 106){
	                                                return false;
	                                            }else{
	                                                if(B <= 78){
	                                                   return true;
	                                                }else{
	                                                    if(G <= 76){
	                                                        if(B-R <= 72){
	                                                            return false;
	                                                        }else{
	                                                            if(S <= 138){
	                                                                if(a <= 165){
	                                                                    if(b <= 142){
	                                                                        if(B-R <= 77){
	                                                                            if(G <= 75){
	                                                                                if(B-R <= 73){
	                                                                                   return true;
	                                                                                }else{
	                                                                                    if(R <= 155){
	                                                                                       return true;
	                                                                                    }else{
	                                                                                        if(G-R <= 85){
	                                                                                            if(H <= 177){
	                                                                                                if(B-G <= 7){
	                                                                                                   return true;
	                                                                                                }else{
	                                                                                                    return false;
	                                                                                                }

	                                                                                            }else{
	                                                                                                if(R <= 156){
	                                                                                                    return false;
	                                                                                                }else{
	                                                                                                   return true;
	                                                                                                }
	                                                                                            }

	                                                                                        }else{
	                                                                                           return true;
	                                                                                        }
	                                                                                    }
	                                                                                }

	                                                                            }else{
	                                                                                return false;
	                                                                            }

	                                                                        }else{
	                                                                            return false;
	                                                                        }

	                                                                    }else{
	                                                                       return true;
	                                                                    }

	                                                                }else{
	                                                                   return true;
	                                                                }

	                                                            }else{
	                                                                if(a <= 166){
	                                                                    return false;
	                                                                }else{
	                                                                    if(B-R <= 88){
	                                                                        if(H <= 177){
	                                                                            if(B-G <= 9){
	                                                                                return false;
	                                                                            }else{
	                                                                                if(R <= 168){
	                                                                                    return false;
	                                                                                }else{
	                                                                                   return true;
	                                                                                }
	                                                                            }

	                                                                        }else{
	                                                                           return true;
	                                                                        }

	                                                                    }else{
	                                                                        if(S <= 141){
	                                                                           return true;
	                                                                        }else{
	                                                                            return false;
	                                                                        }
	                                                                    }
	                                                                }
	                                                            }
	                                                        }

	                                                    }else{
	                                                        if(R <= 163){
	                                                            if(B <= 79){
	                                                                return false;
	                                                            }else{
	                                                                if(H <= 178){
	                                                                    if(b <= 138){
	                                                                        if(S <= 126){
	                                                                            return false;
	                                                                        }else{
	                                                                           return true;
	                                                                        }

	                                                                    }else{
	                                                                        if(H <= 177){
	                                                                            if(B-R <= 73){
	                                                                                return false;
	                                                                            }else{
	                                                                               return true;
	                                                                            }

	                                                                        }else{
	                                                                            return false;
	                                                                        }
	                                                                    }

	                                                                }else{
	                                                                   return true;
	                                                                }
	                                                            }

	                                                        }else{
	                                                            return false;
	                                                        }
	                                                    }
	                                                }
	                                            }
	                                        }
	                                    }

	                                }else{
	                                    if(B-R <= 100){
	                                        return false;
	                                    }else{
	                                        if(G <= 68){
	                                            if(S <= 161){
	                                               return true;
	                                            }else{
	                                                return false;
	                                            }

	                                        }else{
	                                            if(B-G <= 8){
	                                                if(L <= 119){
	                                                    return false;
	                                                }else{
	                                                    if(S <= 154){
	                                                        if(G-R <= 108){
	                                                            if(H <= 18){
	                                                                return false;
	                                                            }else{
	                                                               return true;
	                                                            }

	                                                        }else{
	                                                            if(H <= 18){
	                                                                if(B-R <= 109){
	                                                                    return false;
	                                                                }else{
	                                                                   return true;
	                                                                }

	                                                            }else{
	                                                                if(S <= 150){
	                                                                    if(G <= 76){
	                                                                        if(B <= 80){
	                                                                           return true;
	                                                                        }else{
	                                                                            return false;
	                                                                        }

	                                                                    }else{
	                                                                        if(b <= 148){
	                                                                           return true;
	                                                                        }else{
	                                                                            return false;
	                                                                        }
	                                                                    }

	                                                                }else{
	                                                                    if(a <= 174){
	                                                                        if(B-G <= 7){
	                                                                            if(G-R <= 112){
	                                                                                if(G-R <= 111){
	                                                                                    return false;
	                                                                                }else{
	                                                                                   return true;
	                                                                                }

	                                                                            }else{
	                                                                                return false;
	                                                                            }

	                                                                        }else{
	                                                                           return true;
	                                                                        }

	                                                                    }else{
	                                                                        return false;
	                                                                    }
	                                                                }
	                                                            }
	                                                        }

	                                                    }else{
	                                                        if(R <= 188){
	                                                            if(L <= 120){
	                                                                if(S <= 155){
	                                                                   return true;
	                                                                }else{
	                                                                    return false;
	                                                                }

	                                                            }else{
	                                                                return false;
	                                                            }

	                                                        }else{
	                                                           return true;
	                                                        }
	                                                    }
	                                                }

	                                            }else{
	                                                return false;
	                                            }
	                                        }
	                                    }
	                                }
	                            }

	                        }else{
	                            if(b <= 146){
	                                return false;
	                            }else{
	                                if(B <= 78){
	                                    if(L <= 117){
	                                        if(S <= 160){
	                                            if(B <= 76){
	                                               return true;
	                                            }else{
	                                                return false;
	                                            }

	                                        }else{
	                                            if(G-R <= 117){
	                                               return true;
	                                            }else{
	                                                if(L <= 114){
	                                                    return false;
	                                                }else{
	                                                   return true;
	                                                }
	                                            }
	                                        }

	                                    }else{
	                                       return true;
	                                    }

	                                }else{
	                                    if(G-R <= 116){
	                                        return false;
	                                    }else{
	                                       return true;
	                                    }
	                                }
	                            }
	                        }
	                    }

	                }else{
	                   return true;
	                }

	            }else{
	                if(G-R <= 93){
	                    if(R <= 151){
	                        if(H <= 18){
	                            if(G <= 81){
	                                if(b <= 140){
	                                   return true;
	                                }else{
	                                    return false;
	                                }

	                            }else{
	                               return true;
	                            }

	                        }else{
	                            if(G <= 86){
	                                if(b <= 138){
	                                    return false;
	                                }else{
	                                    if(B-G <= 4){
	                                       return true;
	                                    }else{
	                                        return false;
	                                    }
	                                }

	                            }else{
	                                if(G <= 87){
	                                    return false;
	                                }else{
	                                   return true;
	                                }
	                            }
	                        }

	                    }else{
	                        if(a <= 158){
	                            if(b <= 136){
	                                if(S <= 108){
	                                   return true;
	                                }else{
	                                    if(S <= 113){
	                                        if(B-G <= 10){
	                                           return true;
	                                        }else{
	                                            if(B <= 99){
	                                               return true;
	                                            }else{
	                                                return false;
	                                            }
	                                        }

	                                    }else{
	                                        return false;
	                                    }
	                                }

	                            }else{
	                               return true;
	                            }

	                        }else{
	                            if(b <= 139){
	                                if(R <= 174){
	                                    if(G <= 86){
	                                        if(B-G <= 10){
	                                            if(G <= 79){
	                                                if(B-R <= 74){
	                                                    return false;
	                                                }else{
	                                                   return true;
	                                                }

	                                            }else{
	                                                if(H <= 176){
	                                                    if(B-G <= 9){
	                                                        if(B-R <= 66){
	                                                           return true;
	                                                        }else{
	                                                            return false;
	                                                        }

	                                                    }else{
	                                                        return false;
	                                                    }

	                                                }else{
	                                                    if(B-G <= 8){
	                                                       return true;
	                                                    }else{
	                                                        if(L <= 113){
	                                                            return false;
	                                                        }else{
	                                                            if(a <= 163){
	                                                                if(R <= 162){
	                                                                   return true;
	                                                                }else{
	                                                                    return false;
	                                                                }

	                                                            }else{
	                                                                if(B-G <= 9){
	                                                                   return true;
	                                                                }else{
	                                                                    if(G <= 80){
	                                                                        return false;
	                                                                    }else{
	                                                                       return true;
	                                                                    }
	                                                                }
	                                                            }
	                                                        }
	                                                    }
	                                                }
	                                            }

	                                        }else{
	                                            if(a <= 164){
	                                                return false;
	                                            }else{
	                                                if(L <= 114){
	                                                    return false;
	                                                }else{
	                                                    if(B-G <= 11){
	                                                       return true;
	                                                    }else{
	                                                        if(R <= 170){
	                                                            if(R <= 167){
	                                                               return true;
	                                                            }else{
	                                                                return false;
	                                                            }

	                                                        }else{
	                                                           return true;
	                                                        }
	                                                    }
	                                                }
	                                            }
	                                        }

	                                    }else{
	                                        if(S <= 122){
	                                            if(S <= 111){
	                                                if(H <= 175){
	                                                    return false;
	                                                }else{
	                                                   return true;
	                                                }

	                                            }else{
	                                               return true;
	                                            }

	                                        }else{
	                                            if(B <= 96){
	                                               return true;
	                                            }else{
	                                                return false;
	                                            }
	                                        }
	                                    }

	                                }else{
	                                    if(B <= 106){
	                                        if(L <= 130){
	                                            if(L <= 123){
	                                                return false;
	                                            }else{
	                                                if(H <= 176){
	                                                    if(B-G <= 10){
	                                                       return true;
	                                                    }else{
	                                                        if(L <= 126){
	                                                            if(R <= 179){
	                                                               return true;
	                                                            }else{
	                                                                return false;
	                                                            }

	                                                        }else{
	                                                            return false;
	                                                        }
	                                                    }

	                                                }else{
	                                                    if(B <= 103){
	                                                        return false;
	                                                    }else{
	                                                        if(B-G <= 7){
	                                                            return false;
	                                                        }else{
	                                                           return true;
	                                                        }
	                                                    }
	                                                }
	                                            }

	                                        }else{
	                                            return false;
	                                        }

	                                    }else{
	                                        if(G <= 99){
	                                            return false;
	                                        }else{
	                                           return true;
	                                        }
	                                    }
	                                }

	                            }else{
	                                if(B <= 101){
	                                    if(R <= 168){
	                                        if(b <= 140){
	                                           return true;
	                                        }else{
	                                            if(a <= 161){
	                                               return true;
	                                            }else{
	                                                if(B-G <= 6){
	                                                    if(G-R <= 89){
	                                                        if(S <= 128){
	                                                            if(B-G <= 4){
	                                                               return true;
	                                                            }else{
	                                                                return false;
	                                                            }

	                                                        }else{
	                                                            if(B-R <= 79){
	                                                                if(R <= 161){
	                                                                   return true;
	                                                                }else{
	                                                                    return false;
	                                                                }

	                                                            }else{
	                                                                if(H <= 0){
	                                                                    if(b <= 143){
	                                                                        return false;
	                                                                    }else{
	                                                                        if(L <= 114){
	                                                                           return true;
	                                                                        }else{
	                                                                            if(G <= 81){
	                                                                                if(a <= 162){
	                                                                                   return true;
	                                                                                }else{
	                                                                                    if(R <= 166){
	                                                                                        return false;
	                                                                                    }else{
	                                                                                       return true;
	                                                                                    }
	                                                                                }

	                                                                            }else{
	                                                                                return false;
	                                                                            }
	                                                                        }
	                                                                    }

	                                                                }else{
	                                                                   return true;
	                                                                }
	                                                            }
	                                                        }

	                                                    }else{
	                                                        return false;
	                                                    }

	                                                }else{
	                                                    if(G-R <= 88){
	                                                       return true;
	                                                    }else{
	                                                        if(B <= 86){
	                                                            return false;
	                                                        }else{
	                                                           return true;
	                                                        }
	                                                    }
	                                                }
	                                            }
	                                        }

	                                    }else{
	                                        if(B <= 88){
	                                            if(G <= 89){
	                                                if(R <= 171){
	                                                    if(B <= 76){
	                                                       return true;
	                                                    }else{
	                                                        if(H <= 1){
	                                                            if(B-G <= 0){
	                                                               return true;
	                                                            }else{
	                                                                if(b <= 147){
	                                                                    if(G-R <= 80){
	                                                                        return false;
	                                                                    }else{
	                                                                        if(b <= 145){
	                                                                            if(B <= 83){
	                                                                                return false;
	                                                                            }else{
	                                                                                if(R <= 170){
	                                                                                   return true;
	                                                                                }else{
	                                                                                    return false;
	                                                                                }
	                                                                            }

	                                                                        }else{
	                                                                            if(R <= 170){
	                                                                                return false;
	                                                                            }else{
	                                                                               return true;
	                                                                            }
	                                                                        }
	                                                                    }

	                                                                }else{
	                                                                    return false;
	                                                                }
	                                                            }

	                                                        }else{
	                                                            if(a <= 165){
	                                                                if(R <= 170){
	                                                                    if(R <= 169){
	                                                                        if(G <= 86){
	                                                                            if(G <= 85){
	                                                                               return true;
	                                                                            }else{
	                                                                                return false;
	                                                                            }

	                                                                        }else{
	                                                                           return true;
	                                                                        }

	                                                                    }else{
	                                                                        if(B-G <= 2){
	                                                                            return false;
	                                                                        }else{
	                                                                            if(S <= 134){
	                                                                               return true;
	                                                                            }else{
	                                                                                return false;
	                                                                            }
	                                                                        }
	                                                                    }

	                                                                }else{
	                                                                   return true;
	                                                                }

	                                                            }else{
	                                                                if(b <= 144){
	                                                                    if(B-R <= 86){
	                                                                        if(G <= 79){
	                                                                            if(b <= 142){
	                                                                               return true;
	                                                                            }else{
	                                                                                return false;
	                                                                            }

	                                                                        }else{
	                                                                            return false;
	                                                                        }

	                                                                    }else{
	                                                                       return true;
	                                                                    }

	                                                                }else{
	                                                                    return false;
	                                                                }
	                                                            }
	                                                        }
	                                                    }

	                                                }else{
	                                                    if(G-R <= 92){
	                                                        if(b <= 146){
	                                                            return false;
	                                                        }else{
	                                                            if(G-R <= 87){
	                                                               return true;
	                                                            }else{
	                                                                if(B-G <= 2){
	                                                                   return true;
	                                                                }else{
	                                                                    if(B-R <= 93){
	                                                                        return false;
	                                                                    }else{
	                                                                        if(G-R <= 90){
	                                                                            if(G-R <= 89){
	                                                                                if(G <= 87){
	                                                                                    return false;
	                                                                                }else{
	                                                                                   return true;
	                                                                                }

	                                                                            }else{
	                                                                                if(R <= 176){
	                                                                                   return true;
	                                                                                }else{
	                                                                                    return false;
	                                                                                }
	                                                                            }

	                                                                        }else{
	                                                                            if(a <= 164){
	                                                                                return false;
	                                                                            }else{
	                                                                                if(G-R <= 91){
	                                                                                    return false;
	                                                                                }else{
	                                                                                   return true;
	                                                                                }
	                                                                            }
	                                                                        }
	                                                                    }
	                                                                }
	                                                            }
	                                                        }

	                                                    }else{
	                                                        if(H <= 1){
	                                                           return true;
	                                                        }else{
	                                                            return false;
	                                                        }
	                                                    }
	                                                }

	                                            }else{
	                                               return true;
	                                            }

	                                        }else{
	                                            if(G <= 99){
	                                                if(S <= 118){
	                                                    if(R <= 174){
	                                                        if(B <= 93){
	                                                            if(R <= 169){
	                                                               return true;
	                                                            }else{
	                                                                return false;
	                                                            }

	                                                        }else{
	                                                           return true;
	                                                        }

	                                                    }else{
	                                                        if(B-R <= 83){
	                                                            if(B <= 97){
	                                                                return false;
	                                                            }else{
	                                                                if(B-G <= 2){
	                                                                    if(G <= 98){
	                                                                        return false;
	                                                                    }else{
	                                                                        if(S <= 115){
	                                                                            return false;
	                                                                        }else{
	                                                                           return true;
	                                                                        }
	                                                                    }

	                                                                }else{
	                                                                    if(b <= 140){
	                                                                        return false;
	                                                                    }else{
	                                                                        if(L <= 129){
	                                                                           return true;
	                                                                        }else{
	                                                                            if(B <= 100){
	                                                                                return false;
	                                                                            }else{
	                                                                               return true;
	                                                                            }
	                                                                        }
	                                                                    }
	                                                                }
	                                                            }

	                                                        }else{
	                                                            if(G-R <= 84){
	                                                               return true;
	                                                            }else{
	                                                                return false;
	                                                            }
	                                                        }
	                                                    }

	                                                }else{
	                                                    if(B-G <= 8){
	                                                        if(B <= 89){
	                                                            if(a <= 164){
	                                                                if(B-G <= 3){
	                                                                    if(G <= 89){
	                                                                        return false;
	                                                                    }else{
	                                                                       return true;
	                                                                    }

	                                                                }else{
	                                                                   return true;
	                                                                }

	                                                            }else{
	                                                                return false;
	                                                            }

	                                                        }else{
	                                                            if(R <= 171){
	                                                               return true;
	                                                            }else{
	                                                                if(B-R <= 82){
	                                                                    if(H <= 177){
	                                                                        if(R <= 179){
	                                                                           return true;
	                                                                        }else{
	                                                                            return false;
	                                                                        }

	                                                                    }else{
	                                                                        if(B-R <= 78){
	                                                                           return true;
	                                                                        }else{
	                                                                            if(b <= 140){
	                                                                                return false;
	                                                                            }else{
	                                                                                if(B <= 96){
	                                                                                    if(a <= 161){
	                                                                                       return true;
	                                                                                    }else{
	                                                                                        if(H <= 178){
	                                                                                            if(S <= 124){
	                                                                                               return true;
	                                                                                            }else{
	                                                                                                if(R <= 172){
	                                                                                                    return false;
	                                                                                                }else{
	                                                                                                    if(R <= 175){
	                                                                                                       return true;
	                                                                                                    }else{
	                                                                                                        return false;
	                                                                                                    }
	                                                                                                }
	                                                                                            }

	                                                                                        }else{
	                                                                                            return false;
	                                                                                        }
	                                                                                    }

	                                                                                }else{
	                                                                                    if(G-R <= 87){
	                                                                                       return true;
	                                                                                    }else{
	                                                                                        return false;
	                                                                                    }
	                                                                                }
	                                                                            }
	                                                                        }
	                                                                    }

	                                                                }else{
	                                                                    if(b <= 141){
	                                                                       return true;
	                                                                    }else{
	                                                                        if(R <= 186){
	                                                                            if(B-G <= 3){
	                                                                                if(L <= 123){
	                                                                                    if(L <= 122){
	                                                                                       return true;
	                                                                                    }else{
	                                                                                        return false;
	                                                                                    }

	                                                                                }else{
	                                                                                   return true;
	                                                                                }

	                                                                            }else{
	                                                                                if(B <= 95){
	                                                                                   return true;
	                                                                                }else{
	                                                                                    if(b <= 142){
	                                                                                        if(R <= 184){
	                                                                                            if(H <= 178){
	                                                                                                return false;
	                                                                                            }else{
	                                                                                                if(S <= 123){
	                                                                                                    return false;
	                                                                                                }else{
	                                                                                                   return true;
	                                                                                                }
	                                                                                            }

	                                                                                        }else{
	                                                                                           return true;
	                                                                                        }

	                                                                                    }else{
	                                                                                        return false;
	                                                                                    }
	                                                                                }
	                                                                            }

	                                                                        }else{
	                                                                            if(b <= 144){
	                                                                                return false;
	                                                                            }else{
	                                                                               return true;
	                                                                            }
	                                                                        }
	                                                                    }
	                                                                }
	                                                            }
	                                                        }

	                                                    }else{
	                                                        if(L <= 117){
	                                                           return true;
	                                                        }else{
	                                                            if(b <= 140){
	                                                                return false;
	                                                            }else{
	                                                               return true;
	                                                            }
	                                                        }
	                                                    }
	                                                }

	                                            }else{
	                                               return true;
	                                            }
	                                        }
	                                    }

	                                }else{
	                                    if(B-R <= 86){
	                                        if(S <= 113){
	                                            if(R <= 186){
	                                                if(B <= 102){
	                                                    return false;
	                                                }else{
	                                                   return true;
	                                                }

	                                            }else{
	                                                return false;
	                                            }

	                                        }else{
	                                            return false;
	                                        }

	                                    }else{
	                                       return true;
	                                    }
	                                }
	                            }
	                        }
	                    }

	                }else{
	                    if(H <= 176){
	                        if(G <= 90){
	                            if(G-R <= 94){
	                                return false;
	                            }else{
	                                if(B-R <= 103){
	                                    if(S <= 137){
	                                        if(b <= 147){
	                                            if(B-G <= 0){
	                                                if(B-R <= 99){
	                                                   return true;
	                                                }else{
	                                                    return false;
	                                                }

	                                            }else{
	                                                return false;
	                                            }

	                                        }else{
	                                            if(B <= 85){
	                                                return false;
	                                            }else{
	                                               return true;
	                                            }
	                                        }

	                                    }else{
	                                        if(b <= 149){
	                                            return false;
	                                        }else{
	                                            if(H <= 1){
	                                               return true;
	                                            }else{
	                                                return false;
	                                            }
	                                        }
	                                    }

	                                }else{
	                                    if(B-R <= 110){
	                                        if(G-R <= 100){
	                                            return false;
	                                        }else{
	                                            if(H <= 0){
	                                                if(S <= 141){
	                                                    if(G <= 85){
	                                                       return true;
	                                                    }else{
	                                                        return false;
	                                                    }

	                                                }else{
	                                                    return false;
	                                                }

	                                            }else{
	                                                if(G-R <= 105){
	                                                    if(G-R <= 101){
	                                                        if(B-G <= 7){
	                                                           return true;
	                                                        }else{
	                                                            return false;
	                                                        }

	                                                    }else{
	                                                        return false;
	                                                    }

	                                                }else{
	                                                    if(G-R <= 107){
	                                                       return true;
	                                                    }else{
	                                                        return false;
	                                                    }
	                                                }
	                                            }
	                                        }

	                                    }else{
	                                        if(b <= 151){
	                                           return true;
	                                        }else{
	                                            if(B-G <= 3){
	                                                return false;
	                                            }else{
	                                               return true;
	                                            }
	                                        }
	                                    }
	                                }
	                            }

	                        }else{
	                            if(H <= 18){
	                                if(B <= 85){
	                                    if(G <= 91){
	                                       return true;
	                                    }else{
	                                        return false;
	                                    }

	                                }else{
	                                   return true;
	                                }

	                            }else{
	                                return false;
	                            }
	                        }

	                    }else{
	                        if(B <= 99){
	                            if(B-G <= 9){
	                                if(B-R <= 88){
	                                    if(H <= 177){
	                                        if(B-G <= 8){
	                                           return true;
	                                        }else{
	                                            if(a <= 167){
	                                                return false;
	                                            }else{
	                                                if(S <= 132){
	                                                    return false;
	                                                }else{
	                                                   return true;
	                                                }
	                                            }
	                                        }

	                                    }else{
	                                        if(b <= 142){
	                                            return false;
	                                        }else{
	                                           return true;
	                                        }
	                                    }

	                                }else{
	                                    if(R <= 179){
	                                        if(a <= 168){
	                                            if(G-R <= 96){
	                                                if(G-R <= 94){
	                                                    if(R <= 174){
	                                                        return false;
	                                                    }else{
	                                                       return true;
	                                                    }

	                                                }else{
	                                                    return false;
	                                                }

	                                            }else{
	                                                if(b <= 143){
	                                                    return false;
	                                                }else{
	                                                    if(G-R <= 98){
	                                                       return true;
	                                                    }else{
	                                                        return false;
	                                                    }
	                                                }
	                                            }

	                                        }else{
	                                            return false;
	                                        }

	                                    }else{
	                                        if(G-R <= 98){
	                                            if(S <= 137){
	                                                if(S <= 131){
	                                                   return true;
	                                                }else{
	                                                    if(B <= 94){
	                                                        if(B-R <= 93){
	                                                            if(G-R <= 95){
	                                                                if(B-G <= 5){
	                                                                   return true;
	                                                                }else{
	                                                                    return false;
	                                                                }

	                                                            }else{
	                                                               return true;
	                                                            }

	                                                        }else{
	                                                            if(B-R <= 94){
	                                                                return false;
	                                                            }else{
	                                                               return true;
	                                                            }
	                                                        }

	                                                    }else{
	                                                        return false;
	                                                    }
	                                                }

	                                            }else{
	                                               return true;
	                                            }

	                                        }else{
	                                            if(L <= 122){
	                                                if(a <= 169){
	                                                    return false;
	                                                }else{
	                                                    if(L <= 119){
	                                                       return true;
	                                                    }else{
	                                                        if(H <= 178){
	                                                            if(b <= 145){
	                                                                if(B <= 85){
	                                                                   return true;
	                                                                }else{
	                                                                    return false;
	                                                                }

	                                                            }else{
	                                                               return true;
	                                                            }

	                                                        }else{
	                                                            if(B-R <= 98){
	                                                               return true;
	                                                            }else{
	                                                                if(b <= 147){
	                                                                    return false;
	                                                                }else{
	                                                                    if(B-R <= 103){
	                                                                       return true;
	                                                                    }else{
	                                                                        return false;
	                                                                    }
	                                                                }
	                                                            }
	                                                        }
	                                                    }
	                                                }

	                                            }else{
	                                                if(L <= 125){
	                                                    if(B <= 90){
	                                                        if(L <= 124){
	                                                            if(H <= 178){
	                                                                if(B-G <= 7){
	                                                                   return true;
	                                                                }else{
	                                                                    if(b <= 145){
	                                                                        return false;
	                                                                    }else{
	                                                                       return true;
	                                                                    }
	                                                                }

	                                                            }else{
	                                                                if(S <= 148){
	                                                                    return false;
	                                                                }else{
	                                                                   return true;
	                                                                }
	                                                            }

	                                                        }else{
	                                                            if(B <= 89){
	                                                                if(G <= 81){
	                                                                    return false;
	                                                                }else{
	                                                                    if(S <= 142){
	                                                                        if(B-G <= 3){
	                                                                           return true;
	                                                                        }else{
	                                                                            return false;
	                                                                        }

	                                                                    }else{
	                                                                       return true;
	                                                                    }
	                                                                }

	                                                            }else{
	                                                                return false;
	                                                            }
	                                                        }

	                                                    }else{
	                                                       return true;
	                                                    }

	                                                }else{
	                                                    if(a <= 170){
	                                                        if(b <= 146){
	                                                            if(B <= 95){
	                                                                if(G <= 88){
	                                                                    if(B <= 94){
	                                                                        if(B <= 92){
	                                                                            return false;
	                                                                        }else{
	                                                                           return true;
	                                                                        }

	                                                                    }else{
	                                                                        return false;
	                                                                    }

	                                                                }else{
	                                                                   return true;
	                                                                }

	                                                            }else{
	                                                                return false;
	                                                            }

	                                                        }else{
	                                                           return true;
	                                                        }

	                                                    }else{
	                                                        if(R <= 189){
	                                                            if(B <= 90){
	                                                               return true;
	                                                            }else{
	                                                                return false;
	                                                            }

	                                                        }else{
	                                                            return false;
	                                                        }
	                                                    }
	                                                }
	                                            }
	                                        }
	                                    }
	                                }

	                            }else{
	                                if(R <= 186){
	                                    if(L <= 123){
	                                        if(B-G <= 10){
	                                            if(G <= 80){
	                                                return false;
	                                            }else{
	                                               return true;
	                                            }

	                                        }else{
	                                            return false;
	                                        }

	                                    }else{
	                                        if(R <= 182){
	                                            return false;
	                                        }else{
	                                            if(b <= 141){
	                                                if(B-G <= 10){
	                                                    return false;
	                                                }else{
	                                                   return true;
	                                                }

	                                            }else{
	                                               return true;
	                                            }
	                                        }
	                                    }

	                                }else{
	                                    return false;
	                                }
	                            }

	                        }else{
	                            return false;
	                        }
	                    }
	                }
	            }

	        }else{
	            if(B-R <= 112){
	                if(a <= 166){
	                    if(a <= 165){
	                       return true;
	                    }else{
	                        if(S <= 128){
	                            return false;
	                        }else{
	                           return true;
	                        }
	                    }

	                }else{
	                    if(S <= 154){
	                        if(B <= 86){
	                            if(L <= 124){
	                                if(L <= 123){
	                                    return false;
	                                }else{
	                                   return true;
	                                }

	                            }else{
	                                if(B-G <= 2){
	                                    if(B-R <= 111){
	                                        if(B-R <= 108){
	                                            if(B-R <= 106){
	                                                return false;
	                                            }else{
	                                               return true;
	                                            }

	                                        }else{
	                                            return false;
	                                        }

	                                    }else{
	                                       return true;
	                                    }

	                                }else{
	                                    return false;
	                                }
	                            }

	                        }else{
	                            if(B-G <= 6){
	                                if(R <= 194){
	                                    if(H <= 178){
	                                        return false;
	                                    }else{
	                                        if(B <= 89){
	                                           return true;
	                                        }else{
	                                            return false;
	                                        }
	                                    }

	                                }else{
	                                    if(H <= 18){
	                                        if(a <= 168){
	                                           return true;
	                                        }else{
	                                            return false;
	                                        }

	                                    }else{
	                                        return false;
	                                    }
	                                }

	                            }else{
	                                return false;
	                            }
	                        }

	                    }else{
	                        if(G-R <= 116){
	                            return false;
	                        }else{
	                           return true;
	                        }
	                    }
	                }

	            }else{
	                if(G-R <= 112){
	                    if(B-R <= 113){
	                        return false;
	                    }else{
	                       return true;
	                    }

	                }else{
	                   return true;
	                }
	            }
	        }

	    }else{
	        if(B-R <= 104){
	            if(H <= 18){
	                if(B-R <= 88){
	                   return true;
	                }else{
	                    if(R <= 171){
	                       return true;
	                    }else{
	                        if(R <= 173){
	                            return false;
	                        }else{
	                            if(G <= 92){
	                                return false;
	                            }else{
	                               return true;
	                            }
	                        }
	                    }
	                }

	            }else{
	                if(B-G <= 17){
	                    if(B <= 76){
	                        if(b <= 137){
	                            return false;
	                        }else{
	                            if(H <= 176){
	                                if(b <= 144){
	                                    if(a <= 170){
	                                        if(S <= 157){
	                                            if(b <= 141){
	                                                if(G-R <= 95){
	                                                    if(B-R <= 79){
	                                                        if(B <= 74){
	                                                           return true;
	                                                        }else{
	                                                            if(L <= 99){
	                                                                return false;
	                                                            }else{
	                                                               return true;
	                                                            }
	                                                        }

	                                                    }else{
	                                                        return false;
	                                                    }

	                                                }else{
	                                                   return true;
	                                                }

	                                            }else{
	                                                return false;
	                                            }

	                                        }else{
	                                           return true;
	                                        }

	                                    }else{
	                                        if(b <= 142){
	                                            return false;
	                                        }else{
	                                            if(B <= 75){
	                                               return true;
	                                            }else{
	                                                return false;
	                                            }
	                                        }
	                                    }

	                                }else{
	                                   return true;
	                                }

	                            }else{
	                                return false;
	                            }
	                        }

	                    }else{
	                        if(R <= 182){
	                            if(H <= 175){
	                                if(S <= 103){
	                                    if(R <= 165){
	                                        if(B-G <= 14){
	                                            if(R <= 152){
	                                               return true;
	                                            }else{
	                                                return false;
	                                            }

	                                        }else{
	                                            return false;
	                                        }

	                                    }else{
	                                       return true;
	                                    }

	                                }else{
	                                    if(R <= 168){
	                                        return false;
	                                    }else{
	                                        if(R <= 174){
	                                            if(B-G <= 15){
	                                                if(R <= 170){
	                                                    if(H <= 174){
	                                                       return true;
	                                                    }else{
	                                                        if(R <= 169){
	                                                            if(B-G <= 14){
	                                                                return false;
	                                                            }else{
	                                                                if(a <= 166){
	                                                                    return false;
	                                                                }else{
	                                                                   return true;
	                                                                }
	                                                            }

	                                                        }else{
	                                                            if(b <= 135){
	                                                               return true;
	                                                            }else{
	                                                                return false;
	                                                            }
	                                                        }
	                                                    }

	                                                }else{
	                                                   return true;
	                                                }

	                                            }else{
	                                                if(R <= 171){
	                                                    return false;
	                                                }else{
	                                                    if(H <= 174){
	                                                        if(b <= 134){
	                                                            return false;
	                                                        }else{
	                                                           return true;
	                                                        }

	                                                    }else{
	                                                        if(b <= 140){
	                                                            if(b <= 136){
	                                                               return true;
	                                                            }else{
	                                                                return false;
	                                                            }

	                                                        }else{
	                                                           return true;
	                                                        }
	                                                    }
	                                                }
	                                            }

	                                        }else{
	                                            if(B <= 94){
	                                                if(L <= 118){
	                                                    return false;
	                                                }else{
	                                                   return true;
	                                                }

	                                            }else{
	                                                return false;
	                                            }
	                                        }
	                                    }
	                                }

	                            }else{
	                                if(H <= 176){
	                                    if(b <= 144){
	                                        if(R <= 177){
	                                            if(R <= 167){
	                                                return false;
	                                            }else{
	                                                if(B-G <= 14){
	                                                    if(B-G <= 13){
	                                                        if(R <= 174){
	                                                           return true;
	                                                        }else{
	                                                            return false;
	                                                        }

	                                                    }else{
	                                                        if(B-R <= 97){
	                                                            return false;
	                                                        }else{
	                                                           return true;
	                                                        }
	                                                    }

	                                                }else{
	                                                    if(L <= 109){
	                                                       return true;
	                                                    }else{
	                                                        if(B-R <= 91){
	                                                            if(b <= 141){
	                                                                return false;
	                                                            }else{
	                                                               return true;
	                                                            }

	                                                        }else{
	                                                            return false;
	                                                        }
	                                                    }
	                                                }
	                                            }

	                                        }else{
	                                            return false;
	                                        }

	                                    }else{
	                                        if(B <= 78){
	                                            if(a <= 176){
	                                                return false;
	                                            }else{
	                                                if(G <= 63){
	                                                   return true;
	                                                }else{
	                                                    return false;
	                                                }
	                                            }

	                                        }else{
	                                           return true;
	                                        }
	                                    }

	                                }else{
	                                    return false;
	                                }
	                            }

	                        }else{
	                            if(G-R <= 116){
	                                return false;
	                            }else{
	                                if(B <= 80){
	                                   return true;
	                                }else{
	                                    return false;
	                                }
	                            }
	                        }
	                    }

	                }else{
	                    if(B-R <= 100){
	                        return false;
	                    }else{
	                        if(G <= 58){
	                           return true;
	                        }else{
	                            return false;
	                        }
	                    }
	                }
	            }

	        }else{
	            if(S <= 164){
	                if(b <= 144){
	                    return false;
	                }else{
	                    if(B <= 81){
	                        return false;
	                    }else{
	                       return true;
	                    }
	                }

	            }else{
	               return true;
	            }
	        }
	    }
	}
}


int main(int argc, char const *argv[])
{
	Mat imgNatural = imread(argv[1]);
	Mat imgLab,imgHsv;
	cvtColor(imgNatural,imgLab,COLOR_BGR2Lab);//Cria uma copia da imagem Natural usando LAB
    cvtColor(imgNatural,imgHsv,COLOR_BGR2HSV);//Cria uma copia da imagem Natural usando HSV
	
    //CRIAÇAO DA MASCARA DA FERIDA

    Mat gray_image,mediana,mascara;
 	cvtColor( imgNatural, gray_image, CV_BGR2GRAY );

 	medianBlur(gray_image,mediana,3);//FILTRO PASSA BAIXA
 	mascara = mediana.clone(); //CLONAGEM DA IMAGEM PASSADA A MEDIA

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
	threshold( mediana, mascara, Media,255,0);
	imwrite( "masc.png", mascara);
  	mascara = imread("masc.png",1);
 	//FIM CRIAÇAO MASCARA DA FERIDA

    Vec3b pixelRGB;
    Vec3b pixelLab;
    Vec3b pixelHSV;
    int R,G,B,L,a,b,H,S,V,B_G,G_R,B_R;

	int coluna = imgNatural.size().width;
    int linha = imgNatural.size().height;
    bool natural;
    int x,y,pat=0,nor=0;
    clock_t Ticks[2];
    Ticks[0] = clock();
    for(x=0; x < linha; x++)
    {
    	for (y = 0; y < coluna; y++)
    	{
            natural = false;
            if(isMasc(mascara.at<Vec3b>(x,y)))
            {
                pixelRGB = imgNatural.at<Vec3b>(x, y); //Pixel RGB
                pixelLab = imgLab.at<Vec3b>(x, y);     //Pixel LAB
                pixelHSV = imgHsv.at<Vec3b>(x, y);     //Pixel HSV
                B = (int)pixelRGB.val[0];
                G = (int)pixelRGB.val[1];
                R = (int)pixelRGB.val[2];
                L = (int)pixelLab.val[0];
                a = (int)pixelLab.val[1];
                b = (int)pixelLab.val[2];
                H = (int)pixelHSV.val[0];
                S = (int)pixelHSV.val[1];
                V = (int)pixelHSV.val[2];
                B_R = B - R;
                B_G = B - G;
                G_R = G - R;
                
                natural = Tree(B,G,R,L,a,b,H,S,V,B_R,B_G,G_R);
                if(natural){
                    nor++;
                    imgNatural.at<Vec3b>(x, y) = (Vec3b){0,255,0};
                }else{
                    imgNatural.at<Vec3b>(x, y) = (Vec3b){255,0,0};
                    pat++;
                }   
            }
    	}
    }
    //nor = lvl2
    //pat = lvl1
    medianBlur(imgNatural,imgNatural,3);//FILTRO PASSA BAIXA
    imwrite(argv[2],imgNatural);
    float porcentagem;
    if(nor>pat){
    	porcentagem = (float)((nor*100)/(nor+pat));
    	printf("%f DE CHANCE DE SER FERIDA DE LVL 2\n",porcentagem);

    }else{
    	porcentagem = (float)((pat*100)/(nor+pat));
    	printf("%f DE CHANCE DE SER FERIDA DE LVL 1\n",porcentagem);
    }
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("%g\n", Tempo);


	return 0;
}

