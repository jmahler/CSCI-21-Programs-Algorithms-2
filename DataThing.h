
class DataThing {
	int id;
	static int setid;

	DataThing() {
		id = setid++;	
	}

	virtual ~DataThing() {

	}
};
