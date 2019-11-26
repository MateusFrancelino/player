#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <windows.h>
#include <dirent.h>
#include <fstream>
using namespace std;
#undef main
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
 Mix_Music *musica;// para musicas


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
     arquivosom<<endl<<lsdir->d_name;

 }


 char *caminho="musica.mp3";
 musica= Mix_LoadMUS(("C:/teste/beyblade.mp3"));

 closedir(dir);

//Mix_PlayChannel(-1,som,0);
Mix_PlayMusic(musica,0);
while(1){

}

 Mix_CloseAudio();
 //Mix_FreeChunk(som);
Mix_FreeMusic(musica);
}
