void hist(){

	TCanvas *c = new TCanvas("canvas_name", "canvas_title", 100, 50, 950, 560);
	c->SetTickx();
	c->SetTicky();
	c->SetGrid();


	TPad *ci = new TPad("padding_i", "The Histogram", 0.02, 0.98, 0.98, 0.50, 21);
	TPad *cj = new TPad("padding_j", "FFT Histogram", 0.02, 0.05, 0.98, 0.50, 18);
	ci->GetFrame()->SetFillColor(42);
	cj->GetFrame()->SetFillColor(42);
	ci->Draw();
	cj->Draw();
	ci->cd();


	TH1F *hist = new TH1F("hist_name", "hist_title", 100, 0, 17);
	hist->GetXaxis()->SetTitle("Distribution");
	hist->GetYaxis()->SetTitle("No. of Entries");
	hist->SetFillColor(kGreen - 9);
	hist->GetXaxis()->SetTitleSize(0.03);
	hist->GetXaxis()->SetLabelSize(0.03);
	hist->GetYaxis()->SetTitleSize(0.03);
	hist->GetYaxis()->SetLabelSize(0.03);

	fstream datfile;
	datfile.open("data.dat", ios::in);
	
	double value;
	while (true){
	
		datfile >> value;
		hist->Fill(value);
		if (datfile.eof()) break;
	}

	// make a gaussian fit
	TF1 *fit = new TF1("fit", "gaus", 0, 17);	// defining name function to use; gaussian
	/* Setting Parameters: helps root create a curve that converges in case it fails to by default */
	fit->SetParameter(0, 40);		//parameter 0 = CONSTANT Parameter; start to max height of histogram
	fit->SetParameter(1, 5.78);		//parameter 1 = MEAN Parameter; 
	fit->SetParameter(2, 2.41);		//parameter 2 = SIGMA Parameter;
	fit->SetLineWidth(3);
	fit->SetLineStyle(2);

	// getting fit parameters from the fit
	double mean = fit->GetParameter(1);
	double sigma = fit->GetParameter(2);

	cout <<" mean: "<<mean<<" sigma: "<<sigma<<" mean/sigma: "<<mean/sigma<<"\n"<<endl; 
	


	hist->Draw();
	/* draws up a fitting curve according to fitting function;
	 * flag R=range, Q=Quiet(no output on terminal), 0=No Curve
	*/
	hist->Fit("fit", "R");
	// hist->Fit("gaus");	// draws up a gaussian fitting curve
	
	// hist->SetStats(0);	// setting stats. 0=No Stats

	TLegend *legend = new TLegend(0.4, 0.8, 0.1, 0.9);
	legend->SetBorderSize(2);
	legend->AddEntry(hist, "data points", "f"); // flags; a = line, p = points, f = filling
	legend->AddEntry(fit, "gaussian fit function", "lpf");
	legend->Draw();

	
	// Lines
	TLine *ln = new TLine(0, 7, 17, 7);	//line startig from x at y height, endig at x at y height
	ln->SetLineWidth(2);
	ln->SetLineColor(kBlack);
	ln->Draw();


	
	// Arrows
	double x0 = 9.0;		// x value
	int bin	= hist->FindBin(x0);
	double y0 = hist->GetBinContent(bin);

	TArrow *arr = new TArrow(11, 16, x0, y0);
	arr->SetLineWidth(2);
	arr->SetArrowSize(0.02);
	arr->SetLineColor(kBlue);
	arr->Draw();



	// TLatex class for text
	TLatex *tt = new TLatex(11, 16, "Important Data Point");
	tt->Draw();


	cj->cd();
	TH1 *hm = 0;
	TVirtualFFT::SetTransform(0);
	hm = hist->FFT(hm, "MAG");
	hm->SetTitle("Transform");
	hm->Draw();


}
