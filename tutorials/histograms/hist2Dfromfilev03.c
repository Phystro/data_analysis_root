{
	FILE *fp;
	int i,n;
	int numChars = 0; // number of all symbols
	int numLines = 0; // number of all lines
	char buff[512];//array for symbols input
	size_t num;


	float last_max_Xvalue = -9999.;
	float max_Xvalue;
	float last_min_Xvalue = 9999.;
	float min_Xvalue;

	float last_max_Yvalue = -9999.;
        float max_Yvalue;
        float last_min_Yvalue = 9999.;
        float min_Yvalue;




//	char * filename = "myfile02.txt";
	char * filename = "testfile.txt";
	fp = fopen(filename,"r");
	if (fp == 0) //file not found
	{
		printf("Unable to open file. Terminating...\n");
		exit(1);
	}
	while ((num = fread(buff,1,512,fp)) > 0) //reading 512-symbols block. num is the number of read symbols. 
	{
		for (i=0;i<num;++i)
		{
			if (buff[i] == '\n')
			{
				++numLines;
			}
		}
	}
	fclose(fp);


 

	const int numL = numLines;
	float x[numL];
	float y[numL];

//	int nn = 0;
	fp = fopen(filename,"r");
	for(i=0;i<numL;i++)
	{
		fscanf(fp,"%f %f",&x[i],&y[i]);

//		printf("Read: x=%f, y=%f\n",x[i],y[i]);
		max_Xvalue = (x[i] >= last_max_Xvalue) ? x[i] : last_max_Xvalue;
		last_max_Xvalue=max_Xvalue;
		min_Xvalue = (x[i] <= last_min_Xvalue) ? x[i] : last_min_Xvalue;
		last_min_Xvalue=min_Xvalue;

		max_Yvalue = (y[i] >= last_max_Yvalue) ? y[i] : last_max_Yvalue;
                last_max_Yvalue=max_Yvalue;
                min_Yvalue = (y[i] <= last_min_Yvalue) ? y[i] : last_min_Yvalue;
                last_min_Yvalue=min_Yvalue;

	}


	fclose(fp);
	printf("Number of lines in file = %i\n\tMin X value = %f\n\tMax X value = %f\n\tMin Y value = %f\n\tMax Y value = %f\n",numLines,min_Xvalue,max_Xvalue,min_Yvalue,max_Yvalue);
/*	printf("Done! Checking:\n");

	for(i=0;i<numLines;i++)
	{
		printf("%f\n",x[i]);
	} 
*/


//	printf("Checkpoint 1\n");

	TH2F* h = new TH2F("myhisto","Histo name;X values description;Y values description",1000,min_Xvalue-1.,max_Xvalue+1.,1000,min_Yvalue-1.,max_Yvalue+1.);

//	printf("Checkpoint 2\n");
//	printf ("nn = %i\n",i);
	for (i=0;i<numL;i++)  //filling histo
	{
//		printf("Attempting to fill x=%f, y=%f from line #%i\n",x[i],y[i],i);
		h->Fill(x[i],y[i],1.);
	}

	
//	printf("Checkpoint 3\n");

	h->Draw(); //drawing histo

//	TFile f("occupancy.root","recreate");
//	h->Write();
//	f.Close();
	
//	printf("Writing to file succeeded, quiting...\n");

	return 0;
}

