public class Main {
    public static void main(String[] args) throws Exception {
        Clock brClock = new ClockBR();
        brClock.setSecond(0);
        brClock.setMinute(0);
        brClock.setHour(13);

        System.out.println(brClock.getTime());

        System.out.println(new ClockUs().convert(brClock).getTime());
    }
}
