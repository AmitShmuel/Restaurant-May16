#ifndef _SPObject_
#define _SPObject_


class SPObject
{
public:
	SPObject();
	virtual ~SPObject() = 0;
	SPObject(const SPObject& rhs);
	SPObject& operator=(const SPObject& rhs);
	void addReference();
	void removeReference();
	void markUnshareable();
	bool isShareable() const;
	bool isShared() const;
private:
	int refCount;
	bool shareable;
};


#endif //_SPObject_