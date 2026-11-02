public class Smartphone implements VideoPlayer, MusicPlayer {

    @Override
    public void pauseMusic() {
        System.out.println("O Smartphone está pausando música");
        
    }

    @Override
    public void playMusic() {
        System.out.println("O Smartphone está tocando música");
        
    }

    @Override
    public void stopMusic() {
        System.out.println("O Smartphone está parando a música");
        
    }

    @Override
    public void pauseVideo() {
        System.out.println("O Smartphone está pausando o vídeo");
        
    }

    @Override
    public void playVideo() {
        System.out.println("O Smartphone está reproduzindo o vídeo");
        
    }

    @Override
    public void stopVideo() {
       System.out.println("O Smartphone está parando o vídeo");
        
    }



}
