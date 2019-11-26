#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <windows.h>
#include <dirent.h>
#include <fstream>
using namespace std;
#undef main

void ler_playlist(){
    ifstream ler;
    string linha;
    ler.open("lista_musica.txt");
    if(ler.is_open()){
        while(getline(ler,linha)){
            if(linha!="."||linha!="..")
                cout<<linha<<endl;

        }
    }cout<<endl<<endl<<endl<<endl<<endl;

}

















int main()
{
 SDL_Init(SDL_INIT_EVERYTHING);
 SDL_Window* janela =SDL_CreateWindow("Player",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,0);
 SDL_Renderer* render= SDL_CreateRenderer(janela,-1,0);
 SDL_SetRenderDrawColor(render,100,100,100,0);


 int frequencia = 22050;
 Uint16 formato = AUDIO_S16SYS;
 int canal = 2;//1 mono 2 stereo
 int buffer = 4096;

 Mix_OpenAudio(frequencia,formato,canal,buffer);//inicia o audio
 //Mix_Chunk *som;// para efeitos
 Mix_Music *musica[99];// para musicas


 //som= Mix_LoadWAV("Pow.wav");


 DIR* dir;
 struct dirent *lsdir;
 dir= opendir("C:\\teste");
 fstream arquivosom;
 if(!arquivosom.is_open()){
     arquivosom.open("lista_musica.txt",std::fstream::out);
 }
 while ((lsdir=readdir(dir))!=NULL)
 {

     cout<<endl<<lsdir->d_name;
     arquivosom<<endl<<"C:/teste/"<<lsdir->d_name;

 }



string local[2];
local[0]="C:/teste/simone-simaria-amor-que-doi-vctemvoz.mp3";
local[1]="C:/teste/shawn-mendes-camila-cabello-senorita-live-from-the-amas-2019.mp3";
// char *caminho="musica.mp3";
 //musica= Mix_LoadMUS(local[1].c_str());
ler_playlist();
 closedir(dir);
int aux=0;
//Mix_PlayChannel(-1,som,0);
musica[9]=Mix_LoadMUS(local[1].c_str());


Mix_PlayMusic(musica[9],0);

while(1){
if(aux==9999){
    musica[8]=Mix_LoadMUS(local[0].c_str());
    Mix_PlayMusic(musica[8],0);

}
aux++;

}

 Mix_CloseAudio();
 //Mix_FreeChunk(som);
Mix_FreeMusic(musica[8]);
}
