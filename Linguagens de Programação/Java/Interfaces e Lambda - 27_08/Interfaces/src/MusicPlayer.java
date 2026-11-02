public interface MusicPlayer {

    //staic são variaveis que pertencem a nossa classe, a nossa interfasse, e não a instancia
    //todas a interfaces que formos declara em uma interface, são obrigatoriamente publicas final e staticas
    //public final static String music = "Parabéns para você";
    //não pode ter construtores na nossa interface: ex.public musicPlayer(){}
    
    void playMusic();

    void pauseMusic();

    void stopMusic();
}
