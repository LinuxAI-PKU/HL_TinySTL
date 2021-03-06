/*********************************************************
名称：uninitialized.h
作用：提供内存处理工具函数
注意：
	①传入的first、last都是形参，所以对它们进行移动无影响
**********************************************************/
#ifndef UNINITIALIZED_H
#define UNINITIALIZED_H

#include"type_traits.h"
#include"construct.h"
#include"iterator.h"

#include<cstring>
namespace TinySTL {
	/*****************************************************
	名称：uninitialized_copy
	作用：将[first,last) 复制到[result，result+(last-first) ),返回复制结束的位置
	*****************************************************/
	template<typename InputIterator, typename ForwardIterator>
	ForwardIterator _uninitialized_copy_aux(InputIterator first,InputIterator last,
		ForwardIterator result, __true_type){
			//暂时用这个，后续使用copy函数
		memcpy(result, first, (last - first) * sizeof(*first));
		return result + (last - first);
	}

	template<typename InputIterator, typename ForwardIterator>
	ForwardIterator _uninitialized_copy_aux(InputIterator first, InputIterator last,
		ForwardIterator result, __false_type) {
		int i = 0;
		for (; first != last; ++first, ++i) {
			construct((result + i), *first);
		}
		return (result + i);
	}

	template<typename InputIterator, typename ForwardIterator>
	ForwardIterator uninitialized_copy(InputIterator first, InputIterator last, ForwardIterator result) {
		typedef typename __type_traits<iterator_traits<ForwardIterator>::value_type>::is_POD_type		IS_POD_TYPE;
		return _uninitialized_copy_aux(first, last, result, IS_POD_TYPE());
	}


	/***********************************************************************
	名称：uninitialized_fill
	作用：对给定的范围[first，last)，按值为x进行对象构造,无返回值
	************************************************************************/
	template<typename ForwardIterator,typename T>
	void _uninitialized_fill_aux(ForwardIterator first, ForwardIterator last, const T& value, __true_type) {
		//后续使用fill算法进行替换
		TinySTL::fill(first, last, value);
	}
	template<typename ForwardIterator, typename T>
	void _uninitialized_fill_aux(ForwardIterator first, ForwardIterator last, const T& value, __false_type) {
		for (; first != last; ++first)
			TinySTL::construct(first, value);
	}

	template<typename ForwardIterator, typename T>
	void uninitialized_fill(ForwardIterator first, ForwardIterator last, const T& value) {
		typedef typename __type_traits<T>::is_POD_type		IS_POD_TYPE;
			_uninitialized_fill_aux(first, last, value, IS_POD_TYPE());
	}


	/**********************************************************************
	名称：uninitialized_fill_n
	作用：对[first，first+n*sizeof(T)）范围内进行n个相同对象的构造，返回填充结束的位置
	***********************************************************************/
	template<typename ForwardIterator, typename Size,typename T>
	ForwardIterator _uninitialized_fill_n_aux(ForwardIterator first, Size n, const T& value, __true_type) {
		return TinySTL::fill_n(first, n, value);
 	}

	template<typename ForwardIterator , typename Size, typename T>
	ForwardIterator _uninitialized_fill_n_aux(ForwardIterator first, Size n, const T& value, __false_type) {
		int i = 0;
		for (; i != n; ++i) {
			construct((T*)(first + i), value);
		}
		return (first + i);
	}

	template<typename ForwardIterator, typename Size, typename T>
	ForwardIterator uninitialized_fill_n(ForwardIterator first, Size n, const T& value) {
		typedef typename __type_traits<iterator_traits<ForwardIterator>::value_type>::is_POD_type		IS_POD_TYPE;
		return _uninitialized_fill_n_aux(first, n, value, IS_POD_TYPE());
	}

} //namespace TinySTL
#endif // !UNINITIALIZED_H
