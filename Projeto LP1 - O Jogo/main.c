#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
       
//funções
void controle();
void sair_allegro();

int sair=0;

struct obj{int wx,wy,x,y,w,h;};
struct obj p={0, 60, 300, 400, 74, 57};//MEXER APENAS NO X,Y // CORRESPONDEM A POSIÇÃO DO SPAWN DO PERSONAGEM
int nTile=0,dir=0,i;

struct caixa{int x, y;};

struct caixa box1;
struct caixa box2;
struct caixa caixas1;
struct caixa caixas2;
struct caixa caixas3;
struct caixa caixas4;
struct caixa caixas5;
struct caixa caixas6;

int main(){
    //premio
    srand((unsigned) time(NULL));
    box2.x=rand()%790;
    box2.y=rand()%590;
    
    //caixas
    int color1,color2,color3;//para não ter q editar caixa por caixa
    
    caixas1.x=100;// x e y são onde spawnam
    caixas1.y=100;
    
    caixas2.x=200;
    caixas2.y=200;
    
    caixas3.x=200;
    caixas3.y=200;
    
    caixas4.x=400;
    caixas4.y=400;
    
    caixas5.x=500;
    caixas5.y=500;
    
    caixas6.x=400;//não anda
    caixas6.y=300;//não anda
    
    color1=0;//0,0,0 = preto
    color2=0;
    color3=0;
    
    //pontuação
    int pontos=0;
    int pntsshow=0;
    int fim=0;
    int acabou=0;
    
    //inicialização
    allegro_init();
    install_keyboard();
    set_close_button_callback(sair_allegro);
    set_color_depth(32);
    set_window_title("O Jogo");
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);
    
    //imagens
    BITMAP *buffer=create_bitmap(800,600);
    BITMAP *mikasa=load_bitmap("img/mikasa.bmp",NULL);
    BITMAP *premio=load_bitmap("img/premio.bmp",NULL);
    BITMAP *caveira=load_bitmap("img/caveira.bmp",NULL);
    BITMAP *caveira2=load_bitmap("img/caveira2.bmp",NULL);
    BITMAP *caveira3=load_bitmap("img/caveira3.bmp",NULL);
    BITMAP *caveira4=load_bitmap("img/caveira4.bmp",NULL);
    BITMAP *caveira5=load_bitmap("img/caveira5.bmp",NULL);
    BITMAP *final=load_bitmap("img/final.bmp",NULL);
    
    //sons
    SAMPLE *moedaw=load_sample("sound/wav/moeda.wav");
    SAMPLE *deliciaw=load_sample("sound/wav/delicia.wav");
    SAMPLE *hitw=load_sample("sound/wav/hit.wav");
    SAMPLE *saindow=load_sample("sound/wav/saindo.wav");
    SAMPLE *boraw=load_sample("sound/wav/bora.wav");
    SAMPLE *acabouw=load_sample("sound/wav/acabou.wav");
    SAMPLE *gemidao=load_sample("sound/wav/gemidao.wav");
    MIDI *fasea=load_midi("sound/midi/morty.mid");
    MIDI *faseb=load_midi("sound/midi/fade.mid");
    MIDI *fasec=load_midi("sound/midi/hallelujah.mid");
    MIDI *fased=load_midi("sound/midi/skyrim.mid");
    
    int music;
    music=(rand()%4);
    
    play_sample(boraw,500,128,1000,0);
    if(music==0)play_midi(fasea,1);
    else if(music==1)play_midi(faseb,1);
    else if(music==2)play_midi(fasec,1);
    else if(music==3)play_midi(fased,1);
    
    while(sair==0){
    
         if(key[KEY_ESC])sair=1;
       
       textprintf_ex(buffer, font, 10, 10, makecol(255,255,255), -1, "PONTOS: %i",pntsshow); // placar
       textprintf_ex(buffer, font, 10, 590, makecol(255,255,255), -1, "Feito por: Augusto Vinicius - UPE: Campus caruaru - SI - 2018");
       
       if(music==0)textprintf_ex(buffer, font, 150, 10, makecol(255,255,255), -1, "Musica: Evil Morty Theme Song ");
       else if(music==1)textprintf_ex(buffer, font, 150, 10, makecol(255,255,255), -1, "Musica: Faded ");
       else if(music==2)textprintf_ex(buffer, font, 150, 10, makecol(255,255,255), -1, "Musica: Hallelujah ");
       else if(music==3)textprintf_ex(buffer, font, 150, 10, makecol(255,255,255), -1, "Musica: Skyrim - Dragonborn ");
       
       if(p.x>810)p.x=-10;
       else if(p.x<-10)p.x=810;
       else if(p.y>610)p.y=-10;
       else if(p.y<-10)p.y=610;
       
       if(fim==0){
       
       if(caixas1.x<=800)caixas1.x+=10;// primeiro caixa horizontal
       else if(caixas1.x>800){caixas1.x=-100;// primeiro caixa horizontal
       caixas1.y=rand()%600;//primeiro caixa horizontal
       }
       
       if(caixas2.y<=600)caixas2.y+=10;// primeiro caixa vertical
       else if(caixas2.y>600){caixas2.y=-100;// primeiro caixa vertical
       caixas2.x=rand()%800;//primeiro caixa vertical
       }
       
       if(caixas3.x<=800)caixas3.x+=10;// segunda caixa horizontal
       else if(caixas3.x>800){caixas3.x=-100;// segunda caixa horizontal
       caixas3.y=rand()%600;//segunda caixa horizontal
       } 
       
       if(caixas4.y<=600)caixas4.y+=10;// segunda caixa vertical
       else if(caixas4.y>600){caixas4.y=-100;// segunda caixa vertical
       caixas4.x=rand()%800;//segunda caixa vertical
       }
       
       if(caixas5.x<=800)caixas5.x+=10;// terceira caixa horizontal
       else if(caixas5.x>800){caixas5.x=-100;// terceira caixa horizontal
       caixas5.y=rand()%600;//terceira caixa horizontal
       }
}
                         
       if(p.x+70 > box2.x && p.x < box2.x+40 && p.y+57 > box2.y && p.y < box2.y+40){
       pontos++;
       pntsshow++;
       play_sample(moedaw,255,128,1000,0);
       box2.x=rand()%620;
       box2.y=rand()%420;
       }//hitbox ganhar ponto
       
       if(p.x+70 > caixas1.x && p.x < caixas1.x+40 && p.y+57 > caixas1.y && p.y < caixas1.y+40){
       pontos--;
       pntsshow--;
       play_sample(hitw,255,128,1000,0);
       p.x=300;
       p.y=400;
       }//hitbox perder
       
       if(p.x+70 > caixas2.x && p.x < caixas2.x+40 && p.y+57 > caixas2.y && p.y < caixas2.y+40){
       pontos--;
       pntsshow--;
       play_sample(hitw,255,128,1000,0);
       p.x=300;
       p.y=400;
       }//hitbox perder
       
       if(fim==1){caixas1.x=150;           caixas1.y=200;
                  caixas2.x=150;           caixas2.y=400;
                  caixas3.x=650;           caixas3.y=200;
                  caixas4.x=650;           caixas4.y=400;
                  caixas5.x=400;           caixas5.y=120;}
                  
       
       if(acabou==1){textprintf_ex(buffer, font, 350, 400, makecol(255,255,255), -1, "FIM");
                                           p.x=370;                 p.y=370;
       }
       
       if(pontos<0)pontos=0;
       
       if(pntsshow<0)pntsshow=0;
       
       if(pontos==10){play_sample(deliciaw,500,128,1000,0);pontos+=100;
       }
       
       if(pontos>=110){
       
       rectfill(buffer, caixas3.x, caixas3.y, caixas3.x+40, caixas3.y+40,makecol(color1,color2,color3));
       draw_sprite(buffer,caveira3,caixas3.x,caixas3.y);
       
       if(p.x+70 > caixas3.x && p.x < caixas3.x+40 && p.y+57 > caixas3.y && p.y < caixas3.y+40){
       pontos--;
       pntsshow--;
       play_sample(hitw,255,128,1000,0);
       p.x=300;
       p.y=400;
       }//hitbox perder
    } 
       if(pontos==120){play_sample(saindow,500,128,1000,0);pontos+=100;
       }
       if(pontos>=220){
       rectfill(buffer, caixas4.x, caixas4.y, caixas4.x+40, caixas4.y+40,makecol(color1,color2,color3));
       draw_sprite(buffer,caveira4,caixas4.x,caixas4.y);
       
       if(p.x+70 > caixas4.x && p.x < caixas4.x+40 && p.y+57 > caixas4.y && p.y < caixas4.y+40){
       pontos--;
       pntsshow--;
       play_sample(hitw,255,128,1000,0);
       p.x=300;
       p.y=400;
       }//hitbox perder
    }
       
       if(pontos>=225){
       rectfill(buffer, caixas5.x, caixas5.y, caixas5.x+40, caixas5.y+40,makecol(color1,color2,color3));
       draw_sprite(buffer,caveira5,caixas5.x,caixas5.y); 
       
       if(p.x+70 > caixas5.x && p.x < caixas5.x+40 && p.y+57 > caixas5.y && p.y < caixas5.y+40){
       pontos--;
       pntsshow--;
       play_sample(hitw,255,128,1000,0);
       p.x=300;
       p.y=400;
       }//hitbox perder
       
    }
       
       if(pontos==230){play_sample(acabouw,500,128,1000,0);pontos+=100;
        p.x=400;                 p.y=500;
       box2.x=900;              box2.y=900;
       }
       if(pontos>=230){
       textprintf_ex(buffer, font, 250, 350, makecol(255,255,255), -1, "ESPERE O GALVAO PARAR DE BERRAR ANTES DE PEGAR O ULTIMO OBJETIVO");
       fim=1;
       rectfill(buffer, caixas6.x, caixas6.y, caixas6.x+40, caixas6.y+40,makecol(color1,color2,color3));
       draw_sprite(buffer,final,caixas6.x,caixas6.y);
       
       if(p.x+70 > caixas6.x && p.x < caixas6.x+40 && p.y+57 > caixas6.y && p.y < caixas6.y+40){
       pntsshow=69;
       play_sample(gemidao,500,128,1000,1);
       caixas6.x=1000;                      caixas6.y=1000;
       acabou=1;
       }              
       }
       
       controle();
       
       rectfill(buffer, box2.x, box2.y, box2.x+40,box2.y+40,makecol(0,0,0));//caixa onde o objetivo se encontra
       
       draw_sprite(buffer,premio,box2.x,box2.y);//objetivo
       masked_blit(mikasa,buffer, p.wx+nTile*74, p.wy-dir*60, p.x, p.y, p.w, p.h); // personagem
       rectfill(buffer, caixas1.x, caixas1.y, caixas1.x+40, caixas1.y+40,makecol(color1,color2,color3));
       rectfill(buffer, caixas2.x, caixas2.y, caixas2.x+40, caixas2.y+40,makecol(color1,color2,color3)); 
       draw_sprite(buffer,caveira,caixas1.x,caixas1.y);  
       draw_sprite(buffer,caveira2,caixas2.x,caixas2.y);         
       draw_sprite(screen,buffer,0,0); 
       rest(50);
       clear(buffer);         
    }
    destroy_bitmap(final);
    destroy_bitmap(caveira);
    destroy_bitmap(caveira2);
    destroy_bitmap(caveira3);
    destroy_bitmap(caveira4);
    destroy_bitmap(caveira5);
    destroy_bitmap(premio);
    destroy_bitmap(mikasa);
    destroy_bitmap(buffer);
    destroy_sample(moedaw);
    destroy_sample(hitw);
    destroy_sample(boraw);
    destroy_sample(saindow);
    destroy_sample(deliciaw);
    destroy_sample(acabouw);
    destroy_sample(gemidao);
    destroy_midi(fasea);
    destroy_midi(faseb);
    destroy_midi(fasec);
    destroy_midi(fased);
    return 0;
}
END_OF_MAIN();

void controle(){
    if(key[KEY_LEFT]){p.x-=10;dir=0;nTile--;} 
    else if(key[KEY_RIGHT]){p.x+=10;dir=-1;nTile++;}
    else if(key[KEY_UP]){p.y-=10;dir=-2;nTile--;}
    else if(key[KEY_DOWN]){p.y+=10;dir=1;nTile++;}
    else {dir=1;nTile=1;}
    
    if(nTile<0)nTile=2;
    if(nTile>2)nTile=0;
}

void sair_allegro(){
     sair=1;
}
