//https://chat.openai.com/c/f24e68e0-aa4a-458f-bb95-60fcf808f6ba
#pragma once
#include "Set.h"
#include "SharedPtr.hpp"


class PredicateBase {
public:
	PredicateBase() = default;
	virtual ~PredicateBase() = default;
	virtual bool operator()(int element) const = 0;
};

template <typename Predicate>
class PredicateWrapper : public PredicateBase {
public:
	explicit PredicateWrapper(Predicate predicate) : predicate_(predicate) {}

	bool operator()(int element) const override {
		return predicate_(element);
	}

private:
	Predicate predicate_;
};
class CriteriaSet :public Set
{
protected:
	SharedPtr<PredicateBase> predicate=nullptr;
	bool (*pred)(int) = nullptr;;
public:
	CriteriaSet(bool (*func)(int));
	template <typename Predicate>
	CriteriaSet(const Predicate& predicate) : predicate(new PredicateWrapper<Predicate>(predicate)) {};
	CriteriaSet()=default;
	CriteriaSet(const CriteriaSet& other);
	bool contains(int el) const  override;
	Set* clone()  const override;
};
