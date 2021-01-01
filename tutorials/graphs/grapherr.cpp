void grapherr(){

	TCanvas *c = new TCanvas("canvas", "error graph", 100, 100, 900, 630);

	TGraphErrors *gr = new TGraphErrors();

	fstream datfile;
	datfile.open("data.dat", ios::in);

	double x, y, dx, dy;
	int n = 0;

	while (true)
	{

		datfile >> x >> y >> dx >> dy;
		
		n = gr->GetN();		// takes actual number of data points

		gr->SetPoint(n, x, y);
		gr->SetPointError(n, dx, dy);

		if ( datfile.eof() ) break;

	}


	gr->Draw("A*");			// A=axis

	TF1 *fit = new TF1("fit", "pol1", 0, 10);
	gr->Fit("fit");
}
