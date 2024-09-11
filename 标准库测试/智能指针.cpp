#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <utility>
#include "initialize.h"
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

template <class T>
struct SpControlBlock {
	T* m_data;
	int m_refcnt;

	explicit SpControlBlock(T* ptr) : m_data(ptr), m_refcnt(1) {}

	SpControlBlock(SpControlBlock&&) = delete;

	~SpControlBlock() {
		delete m_data;
	}
};

template <class T>
struct SharedPtr {
	SpControlBlock<T>* m_cb;

	explicit SharedPtr(T* ptr) : m_cb(new SpControlBlock<T>(ptr)) {
	}

	SharedPtr(const SharedPtr& that) : m_cb(that.m_cb) {
		m_cb->m_refcnt++;
	}

	~SharedPtr() {
		m_cb->m_refcnt--;
		if (m_cb->m_refcnt == 0) {
			delete m_cb;
		}
	}

	T* get() const {
		return m_cb->m_data;
	}

	SharedPtr& operator=(const SharedPtr& other) {
		if (this != &other) {
			if (m_cb) {
				m_cb->m_refcnt--;
				if (m_cb->m_refcnt == 0) {
					delete m_cb;
				}
			}
			m_cb = other.m_cb;
			if (m_cb) {
				m_cb->m_refcnt++;
			}
		}
		return *this;
	}

	T* operator->() const {
		return m_cb->m_data;
	}

	T& operator*() const {
		return *(m_cb->m_data);
	}
};

template<class T, class ...Args>
SharedPtr<T> makeShared(Args && ...args) {
	return SharedPtr<T>(new T(std::forward<Args>(args)...));
}

int main() {
	// TODO :
	SharedPtr<ListNode> a(new ListNode(6));
	SharedPtr<ListNode> b(new ListNode(32));
	SharedPtr<ListNode> c(new ListNode(38));
	a = b = c;
	return 0;
}
