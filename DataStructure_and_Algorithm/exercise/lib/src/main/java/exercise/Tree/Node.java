package exercise.Tree;

import java.util.List;

public class Node<T> {
	private T content;
	private Node<T> parent;
	private List<Node<T>> edges;

	public Node() {
		this.parent = null;
	}
	
	public Node(T content) {
		this.content = content;
		this.parent = null;
	}
	
	public Node(T content, List<Node<T>> edges) {
		this.content = content;
		this.edges = edges;
		this.parent = null;
	}	
	
	//content
	public T getContent() {
		return content;
	}

	public void setContent(T content) {
		this.content = content;
	}
	
	//parent
	public Node<T> getParent() {
		return parent;
	}

	public void setParent(Node<T> parent) {
		this.parent = parent;
	}
	
	//edges
	public List<Node<T>> getEdges() {
		return edges;
	}

	public void setEdges(List<Node<T>> edges) {
		this.edges = edges;
	} 
	
	//edge
	public void addEdge(Node<T> node) {
		edges.add(node);
	}
	
	public Node<T> deleteEdge(int index){
		return edges.remove(index);
	}
}
