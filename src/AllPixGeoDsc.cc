/**
 * Allpix
 * Author: John Idarraga <idarraga@cern.ch> , 2010
 */

#include "AllPixGeoDsc.hh"



AllPixGeoDsc::AllPixGeoDsc(){


}

AllPixGeoDsc::~AllPixGeoDsc(){

}

/* temporary ... this has to be changed by a db com or something like that */

void AllPixGeoDsc::Dump() {

	cout << "Dump geo description for object with Id : " << m_ID << endl;

	cout << "   digitizer : " << m_digitizer << endl;
	cout << "   npix_x = " << m_npix_x << endl;
	cout << "   npix_y = " << m_npix_y << endl;
	cout << "   npix_z = " << m_npix_z << endl;
	cout << "   pixsize_x = " << m_pixsize_x/mm << " [mm]" << endl;
	cout << "   pixsize_y = " << m_pixsize_y/mm << endl;
	cout << "   pixsize_z = " << m_pixsize_z/mm << endl;
	cout << "   sensor_hx = " << m_sensor_hx/mm << ", posx "<< m_sensor_posx/mm << endl;
	cout << "   sensor_hy = " << m_sensor_hy/mm << ", posy "<< m_sensor_posy/mm << endl;
	cout << "   sensor_hz = " << m_sensor_hz/mm << ", posz "<< m_sensor_posz/mm << endl;
	cout << "   chip_hx = " << m_chip_hx/mm << ", posx "<< m_chip_posx/mm << endl;
	cout << "   chip_hy = " << m_chip_hy/mm << ", posy "<< m_chip_posy/mm << endl;
	cout << "   chip_hz = " << m_chip_hz/mm << ", posz "<< m_chip_posz/mm << endl;
	cout << "   pcb_hx = " << m_pcb_hx/mm << endl;
	cout << "   pcb_hy = " << m_pcb_hy/mm << endl;
	cout << "   pcb_hz = " << m_pcb_hz/mm << endl;

}

/*
void AllPixGeoDsc::operator=(AllPixGeoDsc & cp){

	cout << cp.GetSensorDigitizer() << " , " << m_digitizer << endl;
	m_digitizer = cp.GetSensorDigitizer();

}
*/

/*
void AllPixGeoDsc::ReadGeoBits(){

	ifstream ifs( "DetDscrDb/detgeom.txt" , ifstream::in );

#define NCHARS 128

	char temp[NCHARS];
	string tempS;
	double value = 0.;

	while (ifs.good()){

		ifs.getline(temp, NCHARS);
		tempS = temp;

		if(temp[0] == '#' || tempS.empty() ){ // comment or empty string
			continue;
		}

		for(int colItr = 0 ; colItr < 5 ; colItr++){
			value = GetColFromLine(tempS, colItr);
			switch (colItr) {
			case 0:
				m_pcb_hx= value*um;
				break;
			case 1:
				m_pcb_hy= value*um;
				break;
			case 2:
				m_pcb_hz = value*um;
				break;
			case 3:
				m_sensor_posx = value*um;
				break;
			case 4:
				m_sensor_posy = value*um;
				break;
			}
		}

	}

	ifs.close();

}

double AllPixGeoDsc::GetColFromLine(string tempS, int col){

	size_t pos;
	string cutS;

	int localcol = 0;
	double value = 0.;

	//pos = tempS.find(" ");

	while((pos=tempS.find(" ")) != string::npos)
	{
		cutS = tempS.substr(0, pos);
		value = atof(cutS.c_str());

		// in the desired col
		if(localcol == col){
			return value;
		}
		// shrink string
		tempS = tempS.substr(pos+1);
		localcol++;
	}

	// last entry has no extra space, checking last one
	value = atof(tempS.c_str());
	if(localcol == col)
		return value;

	// if reaching this point, the col couldn't be found
	G4cout << "[ERROR] ouch !, couldn't find that colum (AllPixGeoDsc::GetColFromLine)" << endl;
	G4cout << "        giving up, geometry depends on this." << endl;
	exit(1);

	return -1;
}
*/
