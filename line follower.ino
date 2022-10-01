#define fr  A3 
#define br A2
#define bl A0
#define fl A1 
#define motorDA 6
#define motorGR  3
#define motorDR  9
#define motorGA 5
#define dd  A5
#define gg A4
int FL,FR,BL,BR,DD,GG;
int k=0;
byte vitesse;
char x;
void capt() {
  FL=digitalRead(fl);
  FR=digitalRead(fr);
  BL=digitalRead(bl);
  BR=digitalRead(br);
  DD=digitalRead(dd);
  GG=digitalRead(gg);
  }
  void test(){
     DD=digitalRead(dd);
  GG=digitalRead(gg);
  if (DD==GG==0){
    x='b'; 
     DD=digitalRead(dd);
  GG=digitalRead(gg);  
  }
  else if(DD==GG==1){
    x='n';
     DD=digitalRead(dd);
  GG=digitalRead(gg);
  }

  }
    void moteurdroite(int vitesse,char sens)
  {
    switch(sens)
    {
    case'A' :{analogWrite(motorDA,vitesse);analogWrite(motorDR,0);break;}
    case'R' :{analogWrite(motorDA,0);analogWrite(motorDR,vitesse);break;}
    case'S' :{analogWrite(motorDA,0);analogWrite(motorDR,0);break;}
    }
  }
  
      void moteurgauche(int vitesse,char sens){
  
    switch(sens)
    {
    case'A' :{analogWrite(motorGA,vitesse);analogWrite(motorGR,0);break;}
    case'R' :{analogWrite(motorGA,0);analogWrite(motorGR,vitesse);break;}
    case'S' :{analogWrite(motorGA,0);analogWrite(motorGR,0);break;}
  }
  
   }
  void avant(int vitesse){
    moteurdroite(1.5*vitesse,'A');
    moteurgauche(vitesse,'A');
  }
 void derriere(int vitesse){
    moteurdroite(vitesse,'R');
    moteurgauche(1.2*vitesse,'R');
  }
  void droite(int vitesse){
    moteurdroite(vitesse-10,'A');
    moteurgauche(vitesse+40,'A');}
  void gauche(int vitesse)
  {
    moteurdroite(vitesse+40,'A');
    moteurgauche(vitesse-30,'A');
  }
  void surplaced(int vitesse){
    moteurdroite(vitesse,'R');
    moteurgauche(vitesse,'A');}
  void surplaceg(int vitesse){
    moteurdroite(vitesse,'A');
    moteurgauche(vitesse,'R');
  }
  
    
  void  suiveur(byte vitesse){
    capt();
  if (FR || FL)
              {  
                if (( FR && FL)&&(BL && BR))
                   { 
                    avant(vitesse);
                   }
                     else
                   
                         { if (FL)
                            {  gauche(vitesse); 
                            } 
                        else  
                        { 
                          droite(vitesse);
                   }
                  }
                }
                 else
          {  
            if (BL)
            {
             surplaceg(vitesse);
              }
             else if(BR)
             {
                   surplaced(vitesse);
              }
                  }
  }
  void  suiveurinverse(byte vitesse){
    capt();
  if (FR==0 || FL==0)
              {  
                if (( FR==0 && FL==0)&&(BL==0 && BR==0))
                   { 
                    avant(vitesse);
                   }
                     else
                   
                         { if (FL==0)
                            {  gauche(vitesse); 
                            } 
                        else  
                        { 
                          droite(vitesse);
                   }
                  }
                }
                 else
          {  
            if (BL==0)
            {
             surplaceg(vitesse);
              }
             else if(BR==0)
             {
                   surplaced(vitesse);
              }
              
          
              
                  }
  }
    
  
  
  
  
  
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
}
void loop() {

int vitesse=60;
capt();
suiveur(vitesse);
/*if (DD==0&&GG==0){
  k=0;
  suiveur(vitesse);
}
else if ( (DD==0 && GG) && k==0) {
  suiveur(vitesse); 
}
else if ( (DD && GG==0) && k==0) {
  suiveur(vitesse);
}
else if ( DD && GG ) {
  k=1;
  suiveurinverse(vitesse);
}
else if ((DD==0 && GG ) && k==1) {

suiveurinverse(vitesse);

}
else if ((DD && GG==0) && k==1) {
  suiveurinverse(vitesse);
}
*/

}
