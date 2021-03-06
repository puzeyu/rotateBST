#include "rotate_gtest_class.h"

TEST_F(RotateTest, Test17_TransformRotateChildRecursive) 
{
	using Key = int;
	using Value = double;
	InsSeq<Key, Value> ins1{
		std::make_pair(7, 0.0),
		std::make_pair(4, 0.0),
		std::make_pair(1, 0.0),
		std::make_pair(3, 0.0),
		std::make_pair(2, 0.0),
		std::make_pair(6, 0.0),
		std::make_pair(5, 0.0),
		std::make_pair(9, 0.0),
		std::make_pair(8, 0.0),
		std::make_pair(10, 0.0),
		std::make_pair(11, 0.0),
	};
	InsSeq<Key, Value> ins2{
		std::make_pair(1, 1.0),
		std::make_pair(2, 2.0),
		std::make_pair(3, 3.0),
		std::make_pair(4, 4.0),
		std::make_pair(5, 5.0),
		std::make_pair(6, 6.0),
		std::make_pair(7, 7.0),
		std::make_pair(8, 8.0),
		std::make_pair(9, 9.0),
		std::make_pair(10, 10.0),
		std::make_pair(11, 11.0),
	};
	NodeSeq<Key, Value> seq1{
		NodeValidation<Key, Value>{7, 0.0, 5, true, true},
		NodeValidation<Key, Value>{4, 0.0, 4, true, true},
		NodeValidation<Key, Value>{1, 0.0, 3, false, true},
		NodeValidation<Key, Value>{3, 0.0, 2, true, false},
		NodeValidation<Key, Value>{2, 0.0, 1, false, false},
		NodeValidation<Key, Value>{6, 0.0, 2, true, false},
		NodeValidation<Key, Value>{5, 0.0, 1, false, false},
		NodeValidation<Key, Value>{9, 0.0, 3, true, true},
		NodeValidation<Key, Value>{8, 0.0, 1, false, false},
		NodeValidation<Key, Value>{10, 0.0, 2, false, true},
		NodeValidation<Key, Value>{11, 0.0, 1, false, false},
	};
	NodeSeq<Key, Value> seq2{
		NodeValidation<Key, Value>{7, 7.0, 5, true, true},
		NodeValidation<Key, Value>{4, 4.0, 4, true, true},
		NodeValidation<Key, Value>{1, 1.0, 3, false, true},
		NodeValidation<Key, Value>{3, 3.0, 2, true, false},
		NodeValidation<Key, Value>{2, 2.0, 1, false, false},
		NodeValidation<Key, Value>{6, 6.0, 2, true, false},
		NodeValidation<Key, Value>{5, 5.0, 1, false, false},
		NodeValidation<Key, Value>{9, 9.0, 3, true, true},
		NodeValidation<Key, Value>{8, 8.0, 1, false, false},
		NodeValidation<Key, Value>{10, 10.0, 2, false, true},
		NodeValidation<Key, Value>{11, 11.0, 1, false, false},
	};

	InheritedRotate<Key, Value> t1, t2;
	InsertInTree(t1, ins1);
	InsertInTree(t2, ins2);
	t1.transform(t2);
	TreeStructureCheck(t1.getRoot(), seq1, true);
	TreeStructureCheck(t2.getRoot(), seq2, true);
}