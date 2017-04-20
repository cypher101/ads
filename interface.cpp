package interpac;
public interface animal 
{
 public void travel();
}

//interface tree
package interpac;

public interface tree {
	public void branches();
	public void fruit();
}
//interface flower
package interpac;

public interface flower {
	public void leaf();
	public void petals();
}
//class mammal
package interpac;

public class mammal implements animal,tree,flower
{
public void travel()
{
	System.out.println("animals are travel in forest");
}

public void branches()
{
	System.out.println("many branches");
}
public void fruit()
{
	System.out.println("delicious fruit");
}
public void leaf()
{
	System.out.println("green leafs");
}
public void petals()
{
	System.out.println("many petals");
}
public static void main(String args[])
{
	mammal m=new mammal();
	m.travel();
	m.branches();
	m.fruit();
	m.leaf();
	m.petals();
}
}
