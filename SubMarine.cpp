#include "SubMarine.h"


SubMarine::SubMarine(string _SubMarineName, int _SubMarineSize) {
	SubMarinename = _SubMarineName;
	SubMarineSize = _SubMarineSize;

}
SubMarine::SubMarine()
{
}
string SubMarine::getSubMarinename() {
	return SubMarinename;
}
void SubMarine::setSubMarinename(string _SubMarineName) {
	SubMarinename = _SubMarineName;
}
void SubMarine::setSubMarineSize(int _SubMarineSize) {
	SubMarineSize = _SubMarineSize;
}
int SubMarine::getSubMarineSize() {
	return SubMarineSize;
}
void SubMarine::addSubHit() {
	SubHits++;
}
int SubMarine::getSubHits() {
	return SubHits;
}
bool SubMarine::isSink() {
	if (SubHits > SubMarineSize) {
		return true;
	}
	else
	{
		return false;
	}
}

