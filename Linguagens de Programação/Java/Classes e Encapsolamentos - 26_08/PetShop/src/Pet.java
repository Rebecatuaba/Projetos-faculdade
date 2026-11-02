public class Pet {

    private String name;

    private boolean clean;

    //consultor
    public Pet(String name){
        this.name = name;
        this.clean = false;
    }

    public String getName(){
        return name;
    }

    public boolean isClean(){
        return clean;
    }

    public void setClean(final boolean clean){
        this.clean = clean;
    }
    
}
