public class MusicBox implements MusicPlayer {

    @Override
    public void pauseMusic() {
        System.out.println("A MusicBox está pausando música");
        
    }

    @Override
    public void playMusic() {
        System.out.println("A MusicBox está tocando música");
        
    }

    @Override
    public void stopMusic() {
        System.out.println("A MusicBox está parando a música");
        
    }


}
