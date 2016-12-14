#ifndef foreach

#define foreach(elementType, iteratorName, collection) \
	for (std::vector<elementType>::iterator iteratorName = collection.begin(); \
	iteratorName < collection.end(); iteratorName++)

#define foreach_c(elementType, iteratorName, collection) \
	for (std::vector<elementType>::const_iterator iteratorName = collection.begin(); \
	iteratorName < collection.end(); iteratorName++)

#endif // foreach
