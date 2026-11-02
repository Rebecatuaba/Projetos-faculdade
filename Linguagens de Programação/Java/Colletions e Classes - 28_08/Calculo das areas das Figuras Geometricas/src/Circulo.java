public record Circulo(double radius) implements Forma {

    private static final double pi = 3.14;

    @Override
    public double getArea() {
        return pi * (radius * radius);
    }
} 
