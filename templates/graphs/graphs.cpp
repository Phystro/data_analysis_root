/*
 * Graphs Template
 *
*/

void graphs(){

	/* CANVAS */
	TCanvas *c = new TCanvas( "Canvas Name", "Canvas Title", 200, 50, 1500, 750 );	// name, title, dimensions on screen and of canvas
	c->SetFillColor(18);	// background color
	c->SetGrid();		// set drid lines
	c->GetFrame()->SetFillColor(42);	// frame color
	c->GetFrame()->SetBorderMode(5);	// frame border mode
	c->GetFrame()->SetBorderSize(5);	// frame border size

	// gPad->Range(-100, -100, 100, 100);

	
	/* PADDING */
	TPad *paddn = new TPad( "Padding Name", "Padding Title", 0.02, 0.02, 0.98, 0.98, 21 );	// padding % dimensions and color
	paddn->SetGrid();
	paddn->GetFrame()->SetFillColor(42);	// padding frame color
	paddn->GetFrame()->SetBorderMode(-1);	// padding frame border mode
	paddn->GetFrame()->SetBorderSize(5);	// padding frame border size
	// paddn->SetFillStyle(4100);		// transparency of padding. 4000(transparent) - 4100(opaque)
	paddn->Draw();
	paddn->cd();				// activate use of padding on top of current active canvas


	/* TPAVELABEL; embeds text in a pad, for labelling  */
	TPaveLabel *pl = new TPaveLabel( 0.5, 0.5, 0.4, 0.4, "Pave Label Label/One Liner Text" );	// %x_size, %y_size, x_pos, y_pos
	pl->SetFillColor(kYellow);
	pl->Draw();

	TPaveText *pt = new TPaveText( 0.25, 0.7, 0.4, 0.6 );
	pt->SetFillColor(35);
	pt->AddText("Some Pave Text/Several Text Lines_1");
	pt->AddText("Some more Pave Text/Several Text Lines_2");
	pt->Draw();


	/* LEGEND */
	TLegend *l = new TLegend( 0.0, 0.8, 0.3, 1.0, "Legend Title" );	// x_pos, width, length, y_pos
	l->SetFillColor(25);
	//l->AddEntry();
	l->DrawClone("Same");

}
