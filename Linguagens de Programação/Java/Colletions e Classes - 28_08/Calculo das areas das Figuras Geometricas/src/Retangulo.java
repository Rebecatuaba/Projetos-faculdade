public record Retangulo (double height, double base) implements Forma {

    @Override
    public double getArea() {
        return height * base;
    }

}
