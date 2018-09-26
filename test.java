public class Main {

	public static void main(String[] args) {


		Emprestimo e = new Emprestimo();

		Livro l1 = new Livro(1);
		
		Livro l2 = new Livro(2);
		
		 Livro l3 = new Livro(3); 
		
		Item i1 = new Item(l1);
		Item i2 = new Item(l2);
		Item i3 = new Item(l3);
		e.items.add(i1);
		e.items.add(i2);
		e.items.add(i3);
		System.out.print("Data de Empr�stimo: " + e.getDataEmprestimo());
		System.out.print("\nData de Devolu��o: " + e.CalculaDataDevolucao());


		Float f;
		System.out.print(sizeof(null));
		// System.out.print(sizeof(f));


		
		

	}

}