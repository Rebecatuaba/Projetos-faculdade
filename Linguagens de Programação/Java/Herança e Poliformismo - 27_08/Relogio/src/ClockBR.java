public non-sealed class ClockBR extends Clock{

    @Override
    public Clock convert(Clock clock) {
        this.second = clock.getSecond();
        this.minute = clock.getMinute();
        switch (clock) {
            case ClockUs usclock -> this.hour = (usclock.getPeriodIndicator().equals("PM")) ? 
                    usclock.getHour() + 12:
                    usclock.getHour();
               case ClockBR brclock -> this.hour = brclock.getHour();
        }
        return this;
    }
}