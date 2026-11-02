public record Square(int side) implements Forma {

    @Override
    public double getArea() {
        return side * side;
    }

}
