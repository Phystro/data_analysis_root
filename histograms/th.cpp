void th(){

	TCanvas *c = new TCanvas("myc", "Fast Fourier Transform", 800, 600);
	c->SetFillColor(45);

	// a functiont to sample
	TF1 *fsin = new TF1("fsin", "sin(x) +  sin(2*x) + sin(0.5*x) + 1", 0, 4*TMath::Pi() );
	fsin->Draw();


	Int_t n = 25;
	TH1D *hsin = new TH1D("hsin", "hsin", n + 1, 0, 4 * TMath::Pi() );
	Double_t x;


	// fill histogram with function values
	for (Int_t i = 0; i <= n; i++){
	
		x = (Double_t(i)/n) * (4 * TMath::Pi() );
		hsin->SetBinContent(i + 1, fsin->Eval(x) );
	}

	hsin->Draw("same");
	fsin->GetXaxis()->SetLabelSize(0.05);
	fsin->GetYaxis()->SetLabelSize(0.05);

	// computing magnitude of transform
	TH1 *hm = 0;
	TVirtualFFT::SetTransform(0);
	hm = hsin->FFT(hm, "MAG");
	hm->SetTitle("Magnitude of Transform");
	hm->Draw();


}
