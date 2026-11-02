public non-sealed class ClockUs extends Clock {

    private String periodIndicator;

    

    public String getPeriodIndicator() {
        return periodIndicator;
    }

    public void AfterPMPeriod(){
       this.periodIndicator = "PM"; 
    }

    public void BeforePMPeriod(){
       this.periodIndicator = "AM"; 
    }

    public void setHour(int hour) {
        BeforePMPeriod();
        if (hour > 12 && hour <= 23){
            AfterPMPeriod();
            this.hour = hour - 12;
        }else if (hour >= 24){
            this.hour = 0;
        }else{
            this.hour = hour;
        }
    }

    @Override
    Clock convert(Clock clock) {
        this.second = clock.getSecond();
        this.minute = clock.getMinute();
        switch (clock) {
            case ClockUs usclock -> {
                this.hour = usclock.getHour();
                this.periodIndicator = usclock.getPeriodIndicator();
            }
            case ClockBR brclock -> this.setHour(brclock.getHour());
        }
        return this;
    }

    @Override
    public String getTime(){
        return super.getTime() + " " + this.periodIndicator;
    }

    

     
}