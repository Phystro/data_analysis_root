void rootwave(){

	TCanvas *c = new TCanvas("canvas", "sine canvas", 100, 100, 1600, 900);
	c->SetGrid();


	TPad *pni = new TPad("pni", "padding 1", 0.05, 0.50, 0.95, 0.95, 21);
	TPad *pnj = new TPad("pni", "padding 2", 0.05, 0.50, 0.95, 0.05, 21);
	pni->Draw();
	pnj->Draw();


	pni->cd();
/*
	TGraph *gr = new TGraph("data.dat", "%lg %lg");
	gr->Draw();
*/

/*
	TH1F *hist = new TH1F("hist", "wave hist", 100, 0, 721);
	
	fstream datfile;
	datfile.open("data.dat", ios::in);
	int num;
	double value;
	while (true){
		datfile >> num >> value;
		// printf("%d: %f\n", num, value);
		hist->Fill(value);
		if(datfile.eof()) break;
	}

	hist->Draw();
*/

	TF1 *fsin = new TF1("fsin", "sin(x) + sin(2*x)", 0, 64*TMath::Pi() );
	fsin->Draw("AC");

	Int_t n = 100;
	TH1F *hsin = new TH1F("hsin", "hsin", n+1, 0, 4*TMath::Pi() );
	Double_t x;
	for (Int_t i = 0; i <= n; i++){
		x = (Double_t(i)/n) * (4*TMath::Pi() );
		hsin->SetBinContent(i + 1, fsin->Eval(x));
	}
	hsin->Draw("same");



	pnj->cd();


	TH1 *hm = 0;
	TVirtualFFT::SetTransform(0);
	hm = hsin->FFT(hm, "MAG");
	hm->Draw();
	
}
