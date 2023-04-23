package exercise.Tree;

public class Tree<T> {
	private Node<T> root; // must not be deleted till whole datastructure destructed
	private Node<T> iter;
	
	public Tree() {
		this.root = new Node<T>();
		this.iter = root;
	}
	
	public Tree(Node<T> root) {
		this.root = root;
		this.iter = root;
	}
	
	public Tree(T content) {	
		this.root = new Node<T>(content);
		this.iter = root;
	}
	
	public Node<T> iter() {
		return iter;
	}
	
	public void down(int index) {
		this.iter = iter.getEdges().get(index);
	}
	
	public void up() {
		this.iter = iter.getParent();
	}
	
	protected void add(Node<T> parent, Node<T> child) {
		parent.addEdge(child);
	}
	
	protected Node<T> delete(Node<T> parent, int i) {
		return parent.deleteEdge(i);
	}
}
