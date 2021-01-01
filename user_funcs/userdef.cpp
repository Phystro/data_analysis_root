void userdef(){

	TCanvas *c = new TCanvas("c", "c", 600,550);
	c->SetLeftMargin(0.15);
	c->SetGrid();
	c->SetTickx();
	c->SetTicky();


	TF1 *func = new TF1("func", "exp(-[1]*x) * [0]*sin(x)", 0, 10*TMath::Pi() );	// func=name, parameter 0 and parameter 1*x , interval
	/*
	 * Examples of user defained equations
	 * [0] + [1]*x
	 * (x + x^2)
	 * exp(-[1]*x) * [0]*sin(x)
	*/

	func->SetTitle("");
	func->SetParameter(0, 1);
	func->SetParameter(1, 0.1);

	func->GetXaxis()->SetTitle("Test");
	func->GetYaxis()->SetTitle("Test");

	func->Draw();

	// Exporting the plots
	c->Print("func.tex");
}
