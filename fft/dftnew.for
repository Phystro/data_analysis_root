	  PROGRAM DFT
c
c             period search by a discrete fourier transform
c             -- adapted from Sky and Telescope, 9/88, p. 288
c                -The coarse, medium, fine spacing option omitted.
c                -User selects number of frequency bins.
c             revised by Paul Cohen, 5/31/89            
c

	implicit double precision (a-h, o-z)
	real m
	Character*20 infile, outfile
	dimension x(15000), y(15000), dum(15000)
c
c   **** routine to read data, and to set q ****
c
 
	write(*,*) 'Discrete Fourier Transform'
	write(*,*)

	write(*,*) 'Time series file: '
	read(*,1) infile
1       Format (a20)

	write(*,*) 'Number of points in the time series: '
	read(*,*) numpt
	q = 0
	open (1, file = infile,status='old')
	read(1,*) ( x(i), dum(i), I = 1, numpt)

	avgy = 0
	do 10  i = 1, numpt
 10     avgy = avgy + dum(i)
	avgy = avgy/numpt
	do 20  i = 1, numpt
		y(i) = dum(i) - avgy
 20     q = q + y(i)*y(i)

c
c  ***** setting output *****
c

	write(*,*) 'Two column output file: '
	read(*,1) outfile
	open( 2, file = outfile, status = 'new' )

c
c  ***** the initializing routine *****
c

	p2 = 2 * 3.14159265
	l = 0
	x4 = x(numpt) - x(1)
	write(*,*) 'Longest useful period (in seconds) = ',(x4*86400)/2

	write(*,*) 'Longest period to use (in seconds): '
	read(*,*) p9
	write(*,*) 'Shortest period to use (in seconds): '
	read(*,*) p0

	f8 = 1/(p0/86400)
	f1 = 1/(p9/86400)
	Write(*,*) 'Number of frequency bins to use: '
	read(*,*) ibins
	m = (f8-f1)/ibins

c
c  **** the dft *****
c

	z9 = 0
	a5 = 0
	f0 = f1 - m
	co = (numpt - 1)/(numpt * q)
	do 100 k = 1, ibins
		write(*,*) 'Bin ',k
		f = f0 + k*m
		b = p2 * f
		c = 0
		s = 0
		do 110 i = 1, numpt
			a = b * x(i)
			s = s + y(i)* dsin(a)
  110           c = c + y(i)* dcos(a)
		z = (c*c +s*s)*co
		a5 = a5 + z
		if (z .le. z9) then
			goto 120
		endif
		z9 = z
		f9 = f
120             if (j .eq. 2) then
			goto 100
		endif
		write(2,95) (86400/f), z
95              format ( E15.9, 5x, E15.9 )
100     continue
	
	end
