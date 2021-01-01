void dhist(){

	TCanvas *c = new TCanvas("canvas", "Canvas", 100, 200, 1300, 880);
	c->SetTickx();
	c->SetTicky();

	gStyle->SetPalette(kRainBow);	// utilizing rainbow colors when using "colz" flags

	TRandom *rand = new TRandom(10);

	TH2F *hist = new TH2F("hist", "2D Histogram", 100, -1, 1, 100, -1, 1);

	hist->SetStats(0);

	for (int i = 0; i < 1e7; i++){
		
		double x = rand->Gaus();
		double y = rand->Gaus();

		hist->Fill(x, y);
	}

	hist->GetXaxis()->SetTitle("x [cm]");
	hist->GetYaxis()->SetTitle("y [cm]");
	hist->GetZaxis()->SetTitle("Entries");

	hist->SetContour(1000);	// setting smooth transitioning between colors
	hist->Draw("colz");


}
