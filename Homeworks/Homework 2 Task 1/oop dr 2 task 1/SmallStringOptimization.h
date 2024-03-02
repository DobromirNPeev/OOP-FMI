#pragma once
union SmallStringOptimization {
	struct {
		char* heapData;
		size_t size;
	};
	char data[];
};