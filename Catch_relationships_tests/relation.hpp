#pragma once
#include <cstdint>
#include <cstddef>
#include <utility>
#include <vector>
#include <algorithm>
#include <cassert>
#include <memory>
#include <cstring>
#include "common_types.hpp"
#ifndef DCON_NO_VE
#include "ve.hpp"
#endif

#ifdef NDEBUG
#ifdef _MSC_VER
#define DCON_RELEASE_INLINE __forceinline
#else
#define DCON_RELEASE_INLINE inline __attribute__((always_inline))
#endif
#else
#define DCON_RELEASE_INLINE inline
#endif
#pragma warning( push )
#pragma warning( disable : 4324 )

namespace dcon {
	struct load_record {
		bool thingyA : 1;
		bool thingyA_some_value : 1;
		bool thingyB : 1;
		bool thingyB__index : 1;
		bool thingyB_some_value : 1;
		bool relate_same : 1;
		bool relate_same_left : 1;
		bool relate_same_right : 1;
		bool relate_in_array : 1;
		bool relate_in_array_left : 1;
		bool relate_in_array_right : 1;
		bool relate_in_list : 1;
		bool relate_in_list_left : 1;
		bool relate_in_list_right : 1;
		load_record() {
			thingyA = false;
			thingyA_some_value = false;
			thingyB = false;
			thingyB__index = false;
			thingyB_some_value = false;
			relate_same = false;
			relate_same_left = false;
			relate_same_right = false;
			relate_in_array = false;
			relate_in_array_left = false;
			relate_in_array_right = false;
			relate_in_list = false;
			relate_in_list_left = false;
			relate_in_list_right = false;
		}
	};
	//
	// definition of strongly typed index for thingyA_id
	//
	class thingyA_id {
		public:
		using value_base_t = uint16_t;
		using zero_is_null_t = std::true_type;
	
		uint16_t value = 0;
	
		constexpr thingyA_id() noexcept = default;
		explicit constexpr thingyA_id(uint16_t v) noexcept : value(v + 1) {}
		constexpr thingyA_id(thingyA_id const& v) noexcept = default;
		constexpr thingyA_id(thingyA_id&& v) noexcept = default;
	
		thingyA_id& operator=(thingyA_id const& v) noexcept = default;
		thingyA_id& operator=(thingyA_id&& v) noexcept = default;
		constexpr bool operator==(thingyA_id v) const noexcept { return value == v.value; }
		constexpr bool operator!=(thingyA_id v) const noexcept { return value != v.value; }
		explicit constexpr operator bool() const noexcept { return value != uint16_t(0); }
		constexpr DCON_RELEASE_INLINE int32_t index() const noexcept {
			return int32_t(value) - 1;
		}
	};
	
	class thingyA_id_pair {
		public:
		thingyA_id left;
		thingyA_id right;
	};
	
	DCON_RELEASE_INLINE bool is_valid_index(thingyA_id id) { return bool(id); }
	
	//
	// definition of strongly typed index for thingyB_id
	//
	class thingyB_id {
		public:
		using value_base_t = uint16_t;
		using zero_is_null_t = std::true_type;
	
		uint16_t value = 0;
	
		constexpr thingyB_id() noexcept = default;
		explicit constexpr thingyB_id(uint16_t v) noexcept : value(v + 1) {}
		constexpr thingyB_id(thingyB_id const& v) noexcept = default;
		constexpr thingyB_id(thingyB_id&& v) noexcept = default;
	
		thingyB_id& operator=(thingyB_id const& v) noexcept = default;
		thingyB_id& operator=(thingyB_id&& v) noexcept = default;
		constexpr bool operator==(thingyB_id v) const noexcept { return value == v.value; }
		constexpr bool operator!=(thingyB_id v) const noexcept { return value != v.value; }
		explicit constexpr operator bool() const noexcept { return value != uint16_t(0); }
		constexpr DCON_RELEASE_INLINE int32_t index() const noexcept {
			return int32_t(value) - 1;
		}
	};
	
	class thingyB_id_pair {
		public:
		thingyB_id left;
		thingyB_id right;
	};
	
	DCON_RELEASE_INLINE bool is_valid_index(thingyB_id id) { return bool(id); }
	
	//
	// definition of strongly typed index for relate_same_id
	//
	class relate_same_id {
		public:
		using value_base_t = uint16_t;
		using zero_is_null_t = std::true_type;
	
		uint16_t value = 0;
	
		constexpr relate_same_id() noexcept = default;
		explicit constexpr relate_same_id(uint16_t v) noexcept : value(v + 1) {}
		constexpr relate_same_id(relate_same_id const& v) noexcept = default;
		constexpr relate_same_id(relate_same_id&& v) noexcept = default;
	
		relate_same_id& operator=(relate_same_id const& v) noexcept = default;
		relate_same_id& operator=(relate_same_id&& v) noexcept = default;
		constexpr bool operator==(relate_same_id v) const noexcept { return value == v.value; }
		constexpr bool operator!=(relate_same_id v) const noexcept { return value != v.value; }
		explicit constexpr operator bool() const noexcept { return value != uint16_t(0); }
		constexpr DCON_RELEASE_INLINE int32_t index() const noexcept {
			return int32_t(value) - 1;
		}
	};
	
	class relate_same_id_pair {
		public:
		relate_same_id left;
		relate_same_id right;
	};
	
	DCON_RELEASE_INLINE bool is_valid_index(relate_same_id id) { return bool(id); }
	
	//
	// definition of strongly typed index for relate_in_array_id
	//
	class relate_in_array_id {
		public:
		using value_base_t = uint16_t;
		using zero_is_null_t = std::true_type;
	
		uint16_t value = 0;
	
		constexpr relate_in_array_id() noexcept = default;
		explicit constexpr relate_in_array_id(uint16_t v) noexcept : value(v + 1) {}
		constexpr relate_in_array_id(relate_in_array_id const& v) noexcept = default;
		constexpr relate_in_array_id(relate_in_array_id&& v) noexcept = default;
	
		relate_in_array_id& operator=(relate_in_array_id const& v) noexcept = default;
		relate_in_array_id& operator=(relate_in_array_id&& v) noexcept = default;
		constexpr bool operator==(relate_in_array_id v) const noexcept { return value == v.value; }
		constexpr bool operator!=(relate_in_array_id v) const noexcept { return value != v.value; }
		explicit constexpr operator bool() const noexcept { return value != uint16_t(0); }
		constexpr DCON_RELEASE_INLINE int32_t index() const noexcept {
			return int32_t(value) - 1;
		}
	};
	
	class relate_in_array_id_pair {
		public:
		relate_in_array_id left;
		relate_in_array_id right;
	};
	
	DCON_RELEASE_INLINE bool is_valid_index(relate_in_array_id id) { return bool(id); }
	
	//
	// definition of strongly typed index for relate_in_list_id
	//
	class relate_in_list_id {
		public:
		using value_base_t = uint16_t;
		using zero_is_null_t = std::true_type;
	
		uint16_t value = 0;
	
		constexpr relate_in_list_id() noexcept = default;
		explicit constexpr relate_in_list_id(uint16_t v) noexcept : value(v + 1) {}
		constexpr relate_in_list_id(relate_in_list_id const& v) noexcept = default;
		constexpr relate_in_list_id(relate_in_list_id&& v) noexcept = default;
	
		relate_in_list_id& operator=(relate_in_list_id const& v) noexcept = default;
		relate_in_list_id& operator=(relate_in_list_id&& v) noexcept = default;
		constexpr bool operator==(relate_in_list_id v) const noexcept { return value == v.value; }
		constexpr bool operator!=(relate_in_list_id v) const noexcept { return value != v.value; }
		explicit constexpr operator bool() const noexcept { return value != uint16_t(0); }
		constexpr DCON_RELEASE_INLINE int32_t index() const noexcept {
			return int32_t(value) - 1;
		}
	};
	
	class relate_in_list_id_pair {
		public:
		relate_in_list_id left;
		relate_in_list_id right;
	};
	
	DCON_RELEASE_INLINE bool is_valid_index(relate_in_list_id id) { return bool(id); }
	
}

#ifndef DCON_NO_VE
namespace ve {
	template<>
	struct value_to_vector_type_s<dcon::thingyA_id> {
		using type = tagged_vector<dcon::thingyA_id>;
	};
	
	template<>
	struct value_to_vector_type_s<dcon::thingyB_id> {
		using type = tagged_vector<dcon::thingyB_id>;
	};
	
	template<>
	struct value_to_vector_type_s<dcon::relate_same_id> {
		using type = tagged_vector<dcon::relate_same_id>;
	};
	
	template<>
	struct value_to_vector_type_s<dcon::relate_in_array_id> {
		using type = tagged_vector<dcon::relate_in_array_id>;
	};
	
	template<>
	struct value_to_vector_type_s<dcon::relate_in_list_id> {
		using type = tagged_vector<dcon::relate_in_list_id>;
	};
	
}

#endif
namespace dcon {
	namespace detail {
	}

	class data_container;

	namespace internal {
		class alignas(64) thingyA_class {
			private:
			//
			// storage space for some_value of type int32_t
			//
			struct alignas(64) dtype_some_value {
				uint8_t padding[(63 + sizeof(int32_t)) & ~63ui64];
				int32_t values[(sizeof(int32_t) <= 64 ? (uint32_t(1200) + (64ui32 / uint32_t(sizeof(int32_t))) - 1ui32) & ~(64ui32 / uint32_t(sizeof(int32_t)) - 1ui32) : uint32_t(1200))];
				DCON_RELEASE_INLINE auto vptr() const { return values; }
				DCON_RELEASE_INLINE auto vptr() { return values; }
				dtype_some_value() { std::uninitialized_value_construct_n(values - 1, 1 + (sizeof(int32_t) <= 64 ? (uint32_t(1200) + (64ui32 / uint32_t(sizeof(int32_t))) - 1ui32) & ~(64ui32 / uint32_t(sizeof(int32_t)) - 1ui32) : uint32_t(1200))); }
			}
			m_some_value;
			
			uint32_t size_used = 0;


			public:
			friend class data_container;
		};

		class alignas(64) thingyB_class {
			private:
			//
			// storage space for _index of type thingyB_id
			//
			struct dtype__index {
				thingyB_id values[1200];
				DCON_RELEASE_INLINE auto vptr() const { return values; }
				DCON_RELEASE_INLINE auto vptr() { return values; }
				dtype__index() { std::uninitialized_value_construct_n(values, 1200); }
			}
			m__index;
			
			//
			// storage space for some_value of type int32_t
			//
			struct alignas(64) dtype_some_value {
				uint8_t padding[(63 + sizeof(int32_t)) & ~63ui64];
				int32_t values[(sizeof(int32_t) <= 64 ? (uint32_t(1200) + (64ui32 / uint32_t(sizeof(int32_t))) - 1ui32) & ~(64ui32 / uint32_t(sizeof(int32_t)) - 1ui32) : uint32_t(1200))];
				DCON_RELEASE_INLINE auto vptr() const { return values; }
				DCON_RELEASE_INLINE auto vptr() { return values; }
				dtype_some_value() { std::uninitialized_value_construct_n(values - 1, 1 + (sizeof(int32_t) <= 64 ? (uint32_t(1200) + (64ui32 / uint32_t(sizeof(int32_t))) - 1ui32) & ~(64ui32 / uint32_t(sizeof(int32_t)) - 1ui32) : uint32_t(1200))); }
			}
			m_some_value;
			
			thingyB_id first_free = thingyB_id();
			uint32_t size_used = 0;


			public:
			thingyB_class() {
				for(int32_t i = 1200 - 1; i >= 0; --i) {
					m__index.vptr()[i] = first_free;
					first_free = thingyB_id(uint16_t(i));
				}
			}
			friend class data_container;
		};

		class alignas(64) relate_same_class {
			private:
			//
			// storage space for right of type thingyA_id
			//
			struct alignas(64) dtype_right {
				uint8_t padding[(63 + sizeof(thingyA_id)) & ~63ui64];
				thingyA_id values[(sizeof(thingyA_id) <= 64 ? (uint32_t(1200) + (64ui32 / uint32_t(sizeof(thingyA_id))) - 1ui32) & ~(64ui32 / uint32_t(sizeof(thingyA_id)) - 1ui32) : uint32_t(1200))];
				DCON_RELEASE_INLINE auto vptr() const { return values; }
				DCON_RELEASE_INLINE auto vptr() { return values; }
				dtype_right() { std::uninitialized_value_construct_n(values - 1, 1 + (sizeof(thingyA_id) <= 64 ? (uint32_t(1200) + (64ui32 / uint32_t(sizeof(thingyA_id))) - 1ui32) & ~(64ui32 / uint32_t(sizeof(thingyA_id)) - 1ui32) : uint32_t(1200))); }
			}
			m_right;
			
			uint32_t size_used = 0;


			public:
			friend class data_container;
		};

		class alignas(64) relate_in_array_class {
			private:
			//
			// storage space for right of type thingyB_id
			//
			struct alignas(64) dtype_right {
				uint8_t padding[(63 + sizeof(thingyB_id)) & ~63ui64];
				thingyB_id values[(sizeof(thingyB_id) <= 64 ? (uint32_t(1200) + (64ui32 / uint32_t(sizeof(thingyB_id))) - 1ui32) & ~(64ui32 / uint32_t(sizeof(thingyB_id)) - 1ui32) : uint32_t(1200))];
				DCON_RELEASE_INLINE auto vptr() const { return values; }
				DCON_RELEASE_INLINE auto vptr() { return values; }
				dtype_right() { std::uninitialized_value_construct_n(values - 1, 1 + (sizeof(thingyB_id) <= 64 ? (uint32_t(1200) + (64ui32 / uint32_t(sizeof(thingyB_id))) - 1ui32) & ~(64ui32 / uint32_t(sizeof(thingyB_id)) - 1ui32) : uint32_t(1200))); }
			}
			m_right;
			
			//
			// storage space for array_right of type dcon::stable_mk_2_tag
			//
			struct dtype_array_right {
				dcon::stable_mk_2_tag values[1200];
				DCON_RELEASE_INLINE auto vptr() const { return values; }
				DCON_RELEASE_INLINE auto vptr() { return values; }
				dtype_array_right() { std::uninitialized_fill_n(values, 1200, std::numeric_limits<dcon::stable_mk_2_tag>::max()); }
			}
			m_array_right;
			
			dcon::stable_variable_vector_storage_mk_2<relate_in_array_id, 8, 2400 > right_storage;
			uint32_t size_used = 0;


			public:
			friend class data_container;
		};

		class alignas(64) relate_in_list_class {
			private:
			//
			// storage space for right of type thingyB_id
			//
			struct alignas(64) dtype_right {
				uint8_t padding[(63 + sizeof(thingyB_id)) & ~63ui64];
				thingyB_id values[(sizeof(thingyB_id) <= 64 ? (uint32_t(1200) + (64ui32 / uint32_t(sizeof(thingyB_id))) - 1ui32) & ~(64ui32 / uint32_t(sizeof(thingyB_id)) - 1ui32) : uint32_t(1200))];
				DCON_RELEASE_INLINE auto vptr() const { return values; }
				DCON_RELEASE_INLINE auto vptr() { return values; }
				dtype_right() { std::uninitialized_value_construct_n(values - 1, 1 + (sizeof(thingyB_id) <= 64 ? (uint32_t(1200) + (64ui32 / uint32_t(sizeof(thingyB_id))) - 1ui32) & ~(64ui32 / uint32_t(sizeof(thingyB_id)) - 1ui32) : uint32_t(1200))); }
			}
			m_right;
			
			//
			// storage space for link_right of type relate_in_list_id_pair
			//
			struct dtype_link_right {
				relate_in_list_id_pair values[1200];
				DCON_RELEASE_INLINE auto vptr() const { return values; }
				DCON_RELEASE_INLINE auto vptr() { return values; }
				dtype_link_right() { std::uninitialized_value_construct_n(values, 1200); }
			}
			m_link_right;
			
			//
			// storage space for head_back_right of type relate_in_list_id
			//
			struct alignas(64) dtype_head_back_right {
				uint8_t padding[(63 + sizeof(relate_in_list_id)) & ~63ui64];
				relate_in_list_id values[(sizeof(relate_in_list_id) <= 64 ? (uint32_t(1200) + (64ui32 / uint32_t(sizeof(relate_in_list_id))) - 1ui32) & ~(64ui32 / uint32_t(sizeof(relate_in_list_id)) - 1ui32) : uint32_t(1200))];
				DCON_RELEASE_INLINE auto vptr() const { return values; }
				DCON_RELEASE_INLINE auto vptr() { return values; }
				dtype_head_back_right() { std::uninitialized_value_construct_n(values - 1, 1 + (sizeof(relate_in_list_id) <= 64 ? (uint32_t(1200) + (64ui32 / uint32_t(sizeof(relate_in_list_id))) - 1ui32) & ~(64ui32 / uint32_t(sizeof(relate_in_list_id)) - 1ui32) : uint32_t(1200))); }
			}
			m_head_back_right;
			
			uint32_t size_used = 0;


			public:
			friend class data_container;
		};

	}

	class alignas(64) data_container {
		public:
		internal::thingyA_class thingyA;
		internal::thingyB_class thingyB;
		internal::relate_same_class relate_same;
		internal::relate_in_array_class relate_in_array;
		internal::relate_in_list_class relate_in_list;

		//
		// getters for thingyA: some_value
		//
		DCON_RELEASE_INLINE int32_t const& thingyA_get_some_value(thingyA_id id) const noexcept {
			return thingyA.m_some_value.vptr()[id.index()];
		}
		DCON_RELEASE_INLINE int32_t& thingyA_get_some_value(thingyA_id id) noexcept {
			return thingyA.m_some_value.vptr()[id.index()];
		}
		#ifndef DCON_NO_VE
		DCON_RELEASE_INLINE ve::value_to_vector_type<int32_t> thingyA_get_some_value(ve::contiguous_tags<thingyA_id> id) const noexcept {
			return ve::load(id, thingyA.m_some_value.vptr());
		}
		DCON_RELEASE_INLINE ve::value_to_vector_type<int32_t> thingyA_get_some_value(ve::partial_contiguous_tags<thingyA_id> id) const noexcept {
			return ve::load(id, thingyA.m_some_value.vptr());
		}
		DCON_RELEASE_INLINE ve::value_to_vector_type<int32_t> thingyA_get_some_value(ve::tagged_vector<thingyA_id> id) const noexcept {
			return ve::load(id, thingyA.m_some_value.vptr());
		}
		#endif
		
		//
		// setters for thingyA: some_value
		//
		DCON_RELEASE_INLINE void thingyA_set_some_value(thingyA_id id, int32_t value) noexcept {
			thingyA.m_some_value.vptr()[id.index()] = value;
		}
		#ifndef DCON_NO_VE
		DCON_RELEASE_INLINE void thingyA_set_some_value(ve::contiguous_tags<thingyA_id> id, ve::value_to_vector_type<int32_t> values) noexcept {
			ve::store(id, thingyA.m_some_value.vptr(), values);
		}
		DCON_RELEASE_INLINE void thingyA_set_some_value(ve::partial_contiguous_tags<thingyA_id> id, ve::value_to_vector_type<int32_t> values) noexcept {
			ve::store(id, thingyA.m_some_value.vptr(), values);
		}
		DCON_RELEASE_INLINE void thingyA_set_some_value(ve::tagged_vector<thingyA_id> id, ve::value_to_vector_type<int32_t> values) noexcept {
			ve::store(id, thingyA.m_some_value.vptr(), values);
		}
		#endif
		
		uint32_t thingyA_size() const noexcept { return thingyA.size_used; }

		//
		// getters for thingyB: some_value
		//
		DCON_RELEASE_INLINE int32_t const& thingyB_get_some_value(thingyB_id id) const noexcept {
			return thingyB.m_some_value.vptr()[id.index()];
		}
		DCON_RELEASE_INLINE int32_t& thingyB_get_some_value(thingyB_id id) noexcept {
			return thingyB.m_some_value.vptr()[id.index()];
		}
		#ifndef DCON_NO_VE
		DCON_RELEASE_INLINE ve::value_to_vector_type<int32_t> thingyB_get_some_value(ve::contiguous_tags<thingyB_id> id) const noexcept {
			return ve::load(id, thingyB.m_some_value.vptr());
		}
		DCON_RELEASE_INLINE ve::value_to_vector_type<int32_t> thingyB_get_some_value(ve::partial_contiguous_tags<thingyB_id> id) const noexcept {
			return ve::load(id, thingyB.m_some_value.vptr());
		}
		DCON_RELEASE_INLINE ve::value_to_vector_type<int32_t> thingyB_get_some_value(ve::tagged_vector<thingyB_id> id) const noexcept {
			return ve::load(id, thingyB.m_some_value.vptr());
		}
		#endif
		
		//
		// setters for thingyB: some_value
		//
		DCON_RELEASE_INLINE void thingyB_set_some_value(thingyB_id id, int32_t value) noexcept {
			thingyB.m_some_value.vptr()[id.index()] = value;
		}
		#ifndef DCON_NO_VE
		DCON_RELEASE_INLINE void thingyB_set_some_value(ve::contiguous_tags<thingyB_id> id, ve::value_to_vector_type<int32_t> values) noexcept {
			ve::store(id, thingyB.m_some_value.vptr(), values);
		}
		DCON_RELEASE_INLINE void thingyB_set_some_value(ve::partial_contiguous_tags<thingyB_id> id, ve::value_to_vector_type<int32_t> values) noexcept {
			ve::store(id, thingyB.m_some_value.vptr(), values);
		}
		DCON_RELEASE_INLINE void thingyB_set_some_value(ve::tagged_vector<thingyB_id> id, ve::value_to_vector_type<int32_t> values) noexcept {
			ve::store(id, thingyB.m_some_value.vptr(), values);
		}
		#endif
		
		uint32_t thingyB_size() const noexcept { return thingyB.size_used; }

		uint32_t relate_same_size() const noexcept { return relate_same.size_used; }

		uint32_t relate_in_array_size() const noexcept { return relate_in_array.size_used; }

		uint32_t relate_in_list_size() const noexcept { return relate_in_list.size_used; }

		//
		// primary key getters and setters for relate_same: left
		//
		DCON_RELEASE_INLINE thingyA_id relate_same_get_left(relate_same_id id) const noexcept {
			return thingyA_id(thingyA_id::value_base_t(id.index()));
		}
		#ifndef DCON_NO_VE
		DCON_RELEASE_INLINE ve::contiguous_tags<thingyA_id> relate_same_get_left(ve::contiguous_tags<relate_same_id> id) const noexcept {
			return ve::contiguous_tags<thingyA_id>(id.value);
		}
		DCON_RELEASE_INLINE ve::partial_contiguous_tags<thingyA_id> relate_same_get_left(ve::partial_contiguous_tags<relate_same_id> id) const noexcept {
			return ve::partial_contiguous_tags<thingyA_id>(id.value, id.subcount);
		}
		DCON_RELEASE_INLINE ve::tagged_vector<thingyA_id> relate_same_get_left(ve::tagged_vector<relate_same_id> id) const noexcept {
			return ve::tagged_vector<thingyA_id>(id, std::true_type{});
		}
		#endif
		void relate_same_set_left(relate_same_id id, thingyA_id value) noexcept {
			if(bool(value)) {
				delete_relate_same( relate_same_id(relate_same_id::value_base_t(value.index())) );
				internal_move_relationship_relate_same(id, relate_same_id(relate_same_id::value_base_t(value.index())) );
			} else {
				delete_relate_same(id);
			}
		}
		bool relate_same_try_set_left(relate_same_id id, thingyA_id value) noexcept {
			if(bool(value)) {
				if(relate_same_is_valid( relate_same_id(relate_same_id::value_base_t(value.index())) )) return false;
				internal_move_relationship_relate_same(id, relate_same_id(relate_same_id::value_base_t(value.index())) );
			} else {
				delete_relate_same(id);
			}
			return true;
		}
		
		DCON_RELEASE_INLINE relate_same_id thingyA_get_relate_same_as_left(thingyA_id id) const noexcept {
			return relate_same_id(relate_same_id::value_base_t(id.index()));
		}
		#ifndef DCON_NO_VE
		DCON_RELEASE_INLINE ve::contiguous_tags<relate_same_id> thingyA_get_relate_same_as_left(ve::contiguous_tags<thingyA_id> id) const noexcept {
			return ve::contiguous_tags<relate_same_id>(id.value);
		}
		DCON_RELEASE_INLINE ve::partial_contiguous_tags<relate_same_id> thingyA_get_relate_same_as_left(ve::partial_contiguous_tags<thingyA_id> id) const noexcept {
			return ve::partial_contiguous_tags<relate_same_id>(id.value, id.subcount);
		}
		DCON_RELEASE_INLINE ve::tagged_vector<relate_same_id> thingyA_get_relate_same_as_left(ve::tagged_vector<thingyA_id> id) const noexcept {
			return ve::tagged_vector<relate_same_id>(id, std::true_type{});
		}
		#endif
		DCON_RELEASE_INLINE void thingyA_remove_relate_same_as_left(thingyA_id id) noexcept {
			if(relate_same_is_valid(relate_same_id(relate_same_id::value_base_t(id.index())))) {
				delete_relate_same(relate_same_id(relate_same_id::value_base_t(id.index())));
			}
		}
		
		//
		// getters for relate_same: right
		//
		DCON_RELEASE_INLINE thingyA_id const& relate_same_get_right(relate_same_id id) const noexcept {
			return relate_same.m_right.vptr()[id.index()];
		}
		DCON_RELEASE_INLINE thingyA_id& relate_same_get_right(relate_same_id id) noexcept {
			return relate_same.m_right.vptr()[id.index()];
		}
		#ifndef DCON_NO_VE
		DCON_RELEASE_INLINE ve::value_to_vector_type<thingyA_id> relate_same_get_right(ve::contiguous_tags<relate_same_id> id) const noexcept {
			return ve::load(id, relate_same.m_right.vptr());
		}
		DCON_RELEASE_INLINE ve::value_to_vector_type<thingyA_id> relate_same_get_right(ve::partial_contiguous_tags<relate_same_id> id) const noexcept {
			return ve::load(id, relate_same.m_right.vptr());
		}
		DCON_RELEASE_INLINE ve::value_to_vector_type<thingyA_id> relate_same_get_right(ve::tagged_vector<relate_same_id> id) const noexcept {
			return ve::load(id, relate_same.m_right.vptr());
		}
		#endif
		
		//
		// setters for relate_same: right
		//
		DCON_RELEASE_INLINE void relate_same_set_right(relate_same_id id, thingyA_id value) noexcept {
			relate_same.m_right.vptr()[id.index()] = value;
		}
		#ifndef DCON_NO_VE
		DCON_RELEASE_INLINE void relate_same_set_right(ve::contiguous_tags<relate_same_id> id, ve::value_to_vector_type<thingyA_id> values) noexcept {
			ve::store(id, relate_same.m_right.vptr(), values);
		}
		DCON_RELEASE_INLINE void relate_same_set_right(ve::partial_contiguous_tags<relate_same_id> id, ve::value_to_vector_type<thingyA_id> values) noexcept {
			ve::store(id, relate_same.m_right.vptr(), values);
		}
		DCON_RELEASE_INLINE void relate_same_set_right(ve::tagged_vector<relate_same_id> id, ve::value_to_vector_type<thingyA_id> values) noexcept {
			ve::store(id, relate_same.m_right.vptr(), values);
		}
		#endif
		
		//
		// primary key getters and setters for relate_in_array: left
		//
		DCON_RELEASE_INLINE thingyA_id relate_in_array_get_left(relate_in_array_id id) const noexcept {
			return thingyA_id(thingyA_id::value_base_t(id.index()));
		}
		#ifndef DCON_NO_VE
		DCON_RELEASE_INLINE ve::contiguous_tags<thingyA_id> relate_in_array_get_left(ve::contiguous_tags<relate_in_array_id> id) const noexcept {
			return ve::contiguous_tags<thingyA_id>(id.value);
		}
		DCON_RELEASE_INLINE ve::partial_contiguous_tags<thingyA_id> relate_in_array_get_left(ve::partial_contiguous_tags<relate_in_array_id> id) const noexcept {
			return ve::partial_contiguous_tags<thingyA_id>(id.value, id.subcount);
		}
		DCON_RELEASE_INLINE ve::tagged_vector<thingyA_id> relate_in_array_get_left(ve::tagged_vector<relate_in_array_id> id) const noexcept {
			return ve::tagged_vector<thingyA_id>(id, std::true_type{});
		}
		#endif
		void relate_in_array_set_left(relate_in_array_id id, thingyA_id value) noexcept {
			if(bool(value)) {
				delete_relate_in_array( relate_in_array_id(relate_in_array_id::value_base_t(value.index())) );
				internal_move_relationship_relate_in_array(id, relate_in_array_id(relate_in_array_id::value_base_t(value.index())) );
			} else {
				delete_relate_in_array(id);
			}
		}
		bool relate_in_array_try_set_left(relate_in_array_id id, thingyA_id value) noexcept {
			if(bool(value)) {
				if(relate_in_array_is_valid( relate_in_array_id(relate_in_array_id::value_base_t(value.index())) )) return false;
				internal_move_relationship_relate_in_array(id, relate_in_array_id(relate_in_array_id::value_base_t(value.index())) );
			} else {
				delete_relate_in_array(id);
			}
			return true;
		}
		
		DCON_RELEASE_INLINE relate_in_array_id thingyA_get_relate_in_array_as_left(thingyA_id id) const noexcept {
			return relate_in_array_id(relate_in_array_id::value_base_t(id.index()));
		}
		#ifndef DCON_NO_VE
		DCON_RELEASE_INLINE ve::contiguous_tags<relate_in_array_id> thingyA_get_relate_in_array_as_left(ve::contiguous_tags<thingyA_id> id) const noexcept {
			return ve::contiguous_tags<relate_in_array_id>(id.value);
		}
		DCON_RELEASE_INLINE ve::partial_contiguous_tags<relate_in_array_id> thingyA_get_relate_in_array_as_left(ve::partial_contiguous_tags<thingyA_id> id) const noexcept {
			return ve::partial_contiguous_tags<relate_in_array_id>(id.value, id.subcount);
		}
		DCON_RELEASE_INLINE ve::tagged_vector<relate_in_array_id> thingyA_get_relate_in_array_as_left(ve::tagged_vector<thingyA_id> id) const noexcept {
			return ve::tagged_vector<relate_in_array_id>(id, std::true_type{});
		}
		#endif
		DCON_RELEASE_INLINE void thingyA_remove_relate_in_array_as_left(thingyA_id id) noexcept {
			if(relate_in_array_is_valid(relate_in_array_id(relate_in_array_id::value_base_t(id.index())))) {
				delete_relate_in_array(relate_in_array_id(relate_in_array_id::value_base_t(id.index())));
			}
		}
		
		DCON_RELEASE_INLINE relate_in_array_id thingyA_get_relate_in_array(thingyA_id id) const noexcept {
			return relate_in_array_id(relate_in_array_id::value_base_t(id.index()));
		}
		#ifndef DCON_NO_VE
		DCON_RELEASE_INLINE ve::contiguous_tags<relate_in_array_id> thingyA_get_relate_in_array(ve::contiguous_tags<thingyA_id> id) const noexcept {
			return ve::contiguous_tags<relate_in_array_id>(id.value);
		}
		DCON_RELEASE_INLINE ve::partial_contiguous_tags<relate_in_array_id> thingyA_get_relate_in_array(ve::partial_contiguous_tags<thingyA_id> id) const noexcept {
			return ve::partial_contiguous_tags<relate_in_array_id>(id.value, id.subcount);
		}
		DCON_RELEASE_INLINE ve::tagged_vector<relate_in_array_id> thingyA_get_relate_in_array(ve::tagged_vector<thingyA_id> id) const noexcept {
			return ve::tagged_vector<relate_in_array_id>(id, std::true_type{});
		}
		#endif
		DCON_RELEASE_INLINE void thingyA_remove_relate_in_array(thingyA_id id) noexcept {
			if(relate_in_array_is_valid(relate_in_array_id(relate_in_array_id::value_base_t(id.index())))) {
				delete_relate_in_array(relate_in_array_id(relate_in_array_id::value_base_t(id.index())));
			}
		}
		
		//
		// many key getters and setters for relate_in_array: right
		//
		DCON_RELEASE_INLINE thingyB_id relate_in_array_get_right(relate_in_array_id id) const noexcept {
			return relate_in_array.m_right.vptr()[id.index()];
		}
		#ifndef DCON_NO_VE
		DCON_RELEASE_INLINE ve::value_to_vector_type<thingyB_id> relate_in_array_get_right(ve::contiguous_tags<relate_in_array_id> id) const noexcept {
			return ve::load(id, relate_in_array.m_right.vptr());
		}
		DCON_RELEASE_INLINE ve::value_to_vector_type<thingyB_id> relate_in_array_get_right(ve::partial_contiguous_tags<relate_in_array_id> id) const noexcept {
			return ve::load(id, relate_in_array.m_right.vptr());
		}
		DCON_RELEASE_INLINE ve::value_to_vector_type<thingyB_id> relate_in_array_get_right(ve::tagged_vector<relate_in_array_id> id) const noexcept {
			return ve::load(id, relate_in_array.m_right.vptr());
		}
		#endif
		void relate_in_array_set_right(relate_in_array_id id, thingyB_id value) noexcept {
			if(auto old_value = relate_in_array.m_right.vptr()[id.index()]; bool(old_value)) {
				auto& vref = relate_in_array.m_array_right.vptr()[old_value.index()];
				dcon::remove_unique_item(relate_in_array.right_storage, vref, id);
			}
			if(bool(value)) {
				dcon::push_back(relate_in_array.right_storage, relate_in_array.m_array_right.vptr()[value.index()], id);
			}
			relate_in_array.m_right.vptr()[id.index()] = value;
		}
		
		template<typename T>
		DCON_RELEASE_INLINE void thingyB_for_each_relate_in_array_as_right(thingyB_id id, T&& func) const {
			if(bool(id)) {
				auto vrange = dcon::get_range(relate_in_array.right_storage, relate_in_array.m_array_right.vptr()[id.index()]);
				std::for_each(vrange.first, vrange.second, func);
			}
		}
		DCON_RELEASE_INLINE std::pair<relate_in_array_id const*, relate_in_array_id const*> thingyB_range_of_relate_in_array_as_right(thingyB_id id) const {
			if(bool(id)) {
				auto vrange = dcon::get_range(relate_in_array.right_storage, relate_in_array.m_array_right.vptr()[id.index()]);
				return std::pair<relate_in_array_id const*, relate_in_array_id const*>(vrange.first, vrange.second);
			} else {
				return std::pair<relate_in_array_id const*, relate_in_array_id const*>(nullptr, nullptr);
			}
		}
		void thingyB_remove_all_relate_in_array_as_right(thingyB_id id) noexcept {
			auto rng = thingyB_range_of_relate_in_array_as_right(id);
			dcon::local_vector<relate_in_array_id> temp(rng.first, rng.second);
			std::for_each(temp.begin(), temp.end(), [t = this](relate_in_array_id i) { t->delete_relate_in_array(i); });
		}
		
		template<typename T>
		DCON_RELEASE_INLINE void thingyB_for_each_relate_in_array(thingyB_id id, T&& func) const {
			if(bool(id)) {
				auto vrange = dcon::get_range(relate_in_array.right_storage, relate_in_array.m_array_right.vptr()[id.index()]);
				std::for_each(vrange.first, vrange.second, func);
			}
		}
		DCON_RELEASE_INLINE std::pair<relate_in_array_id const*, relate_in_array_id const*> thingyB_range_of_relate_in_array(thingyB_id id) const {
			if(bool(id)) {
				auto vrange = dcon::get_range(relate_in_array.right_storage, relate_in_array.m_array_right.vptr()[id.index()]);
				return std::pair<relate_in_array_id const*, relate_in_array_id const*>(vrange.first, vrange.second);
			} else {
				return std::pair<relate_in_array_id const*, relate_in_array_id const*>(nullptr, nullptr);
			}
		}
		void thingyB_remove_all_relate_in_array(thingyB_id id) noexcept {
			auto rng = thingyB_range_of_relate_in_array_as_right(id);
			dcon::local_vector<relate_in_array_id> temp(rng.first, rng.second);
			std::for_each(temp.begin(), temp.end(), [t = this](relate_in_array_id i) { t->delete_relate_in_array(i); });
		}
		
		//
		// primary key getters and setters for relate_in_list: left
		//
		DCON_RELEASE_INLINE thingyA_id relate_in_list_get_left(relate_in_list_id id) const noexcept {
			return thingyA_id(thingyA_id::value_base_t(id.index()));
		}
		#ifndef DCON_NO_VE
		DCON_RELEASE_INLINE ve::contiguous_tags<thingyA_id> relate_in_list_get_left(ve::contiguous_tags<relate_in_list_id> id) const noexcept {
			return ve::contiguous_tags<thingyA_id>(id.value);
		}
		DCON_RELEASE_INLINE ve::partial_contiguous_tags<thingyA_id> relate_in_list_get_left(ve::partial_contiguous_tags<relate_in_list_id> id) const noexcept {
			return ve::partial_contiguous_tags<thingyA_id>(id.value, id.subcount);
		}
		DCON_RELEASE_INLINE ve::tagged_vector<thingyA_id> relate_in_list_get_left(ve::tagged_vector<relate_in_list_id> id) const noexcept {
			return ve::tagged_vector<thingyA_id>(id, std::true_type{});
		}
		#endif
		void relate_in_list_set_left(relate_in_list_id id, thingyA_id value) noexcept {
			if(bool(value)) {
				delete_relate_in_list( relate_in_list_id(relate_in_list_id::value_base_t(value.index())) );
				internal_move_relationship_relate_in_list(id, relate_in_list_id(relate_in_list_id::value_base_t(value.index())) );
			} else {
				delete_relate_in_list(id);
			}
		}
		bool relate_in_list_try_set_left(relate_in_list_id id, thingyA_id value) noexcept {
			if(bool(value)) {
				if(relate_in_list_is_valid( relate_in_list_id(relate_in_list_id::value_base_t(value.index())) )) return false;
				internal_move_relationship_relate_in_list(id, relate_in_list_id(relate_in_list_id::value_base_t(value.index())) );
			} else {
				delete_relate_in_list(id);
			}
			return true;
		}
		
		DCON_RELEASE_INLINE relate_in_list_id thingyA_get_relate_in_list_as_left(thingyA_id id) const noexcept {
			return relate_in_list_id(relate_in_list_id::value_base_t(id.index()));
		}
		#ifndef DCON_NO_VE
		DCON_RELEASE_INLINE ve::contiguous_tags<relate_in_list_id> thingyA_get_relate_in_list_as_left(ve::contiguous_tags<thingyA_id> id) const noexcept {
			return ve::contiguous_tags<relate_in_list_id>(id.value);
		}
		DCON_RELEASE_INLINE ve::partial_contiguous_tags<relate_in_list_id> thingyA_get_relate_in_list_as_left(ve::partial_contiguous_tags<thingyA_id> id) const noexcept {
			return ve::partial_contiguous_tags<relate_in_list_id>(id.value, id.subcount);
		}
		DCON_RELEASE_INLINE ve::tagged_vector<relate_in_list_id> thingyA_get_relate_in_list_as_left(ve::tagged_vector<thingyA_id> id) const noexcept {
			return ve::tagged_vector<relate_in_list_id>(id, std::true_type{});
		}
		#endif
		DCON_RELEASE_INLINE void thingyA_remove_relate_in_list_as_left(thingyA_id id) noexcept {
			if(relate_in_list_is_valid(relate_in_list_id(relate_in_list_id::value_base_t(id.index())))) {
				delete_relate_in_list(relate_in_list_id(relate_in_list_id::value_base_t(id.index())));
			}
		}
		
		DCON_RELEASE_INLINE relate_in_list_id thingyA_get_relate_in_list(thingyA_id id) const noexcept {
			return relate_in_list_id(relate_in_list_id::value_base_t(id.index()));
		}
		#ifndef DCON_NO_VE
		DCON_RELEASE_INLINE ve::contiguous_tags<relate_in_list_id> thingyA_get_relate_in_list(ve::contiguous_tags<thingyA_id> id) const noexcept {
			return ve::contiguous_tags<relate_in_list_id>(id.value);
		}
		DCON_RELEASE_INLINE ve::partial_contiguous_tags<relate_in_list_id> thingyA_get_relate_in_list(ve::partial_contiguous_tags<thingyA_id> id) const noexcept {
			return ve::partial_contiguous_tags<relate_in_list_id>(id.value, id.subcount);
		}
		DCON_RELEASE_INLINE ve::tagged_vector<relate_in_list_id> thingyA_get_relate_in_list(ve::tagged_vector<thingyA_id> id) const noexcept {
			return ve::tagged_vector<relate_in_list_id>(id, std::true_type{});
		}
		#endif
		DCON_RELEASE_INLINE void thingyA_remove_relate_in_list(thingyA_id id) noexcept {
			if(relate_in_list_is_valid(relate_in_list_id(relate_in_list_id::value_base_t(id.index())))) {
				delete_relate_in_list(relate_in_list_id(relate_in_list_id::value_base_t(id.index())));
			}
		}
		
		//
		// many key getters and setters for relate_in_list: right
		//
		DCON_RELEASE_INLINE thingyB_id relate_in_list_get_right(relate_in_list_id id) const noexcept {
			return relate_in_list.m_right.vptr()[id.index()];
		}
		#ifndef DCON_NO_VE
		DCON_RELEASE_INLINE ve::value_to_vector_type<thingyB_id> relate_in_list_get_right(ve::contiguous_tags<relate_in_list_id> id) const noexcept {
			return ve::load(id, relate_in_list.m_right.vptr());
		}
		DCON_RELEASE_INLINE ve::value_to_vector_type<thingyB_id> relate_in_list_get_right(ve::partial_contiguous_tags<relate_in_list_id> id) const noexcept {
			return ve::load(id, relate_in_list.m_right.vptr());
		}
		DCON_RELEASE_INLINE ve::value_to_vector_type<thingyB_id> relate_in_list_get_right(ve::tagged_vector<relate_in_list_id> id) const noexcept {
			return ve::load(id, relate_in_list.m_right.vptr());
		}
		#endif
		void relate_in_list_set_right(relate_in_list_id id, thingyB_id value) noexcept {
			if(auto old_value = relate_in_list.m_right.vptr()[id.index()]; bool(old_value)) {
				if(auto old_left = relate_in_list.m_link_right.vptr()[id.index()].left; bool(old_left)) {
					relate_in_list.m_link_right.vptr()[old_left.index()].right = relate_in_list.m_link_right.vptr()[id.index()].right;
				} else {
					relate_in_list.m_head_back_right.vptr()[old_value.index()] = relate_in_list.m_link_right.vptr()[id.index()].right;
				}
				if(auto old_right = relate_in_list.m_link_right.vptr()[id.index()].right; bool(old_right)) {
					relate_in_list.m_link_right.vptr()[old_right.index()].left = relate_in_list.m_link_right.vptr()[id.index()].left;
				}
			}
			if(bool(value)) {
				if(auto existing_list = relate_in_list.m_head_back_right.vptr()[value.index()]; bool(existing_list)) {
					relate_in_list.m_link_right.vptr()[id.index()].left = existing_list;
					if(auto r = relate_in_list.m_link_right.vptr()[existing_list.index()].right; bool(r)) {
						relate_in_list.m_link_right.vptr()[id.index()].right = r;
						relate_in_list.m_link_right.vptr()[r.index()].left = id;
					} else {
						relate_in_list.m_link_right.vptr()[id.index()].right = relate_in_list_id();
					}
					relate_in_list.m_link_right.vptr()[existing_list.index()].right = id;
					relate_in_list.m_head_back_right.vptr()[value.index()] = existing_list;
				} else {
					relate_in_list.m_head_back_right.vptr()[value.index()] = id;
					relate_in_list.m_link_right.vptr()[id.index()].right = relate_in_list_id();
					relate_in_list.m_link_right.vptr()[id.index()].left = relate_in_list_id();
				}
			} else {
				relate_in_list.m_link_right.vptr()[id.index()].right = relate_in_list_id();
				relate_in_list.m_link_right.vptr()[id.index()].left = relate_in_list_id();
			}
			relate_in_list.m_right.vptr()[id.index()] = value;
		}
		
		template<typename T>
		DCON_RELEASE_INLINE void thingyB_for_each_relate_in_list_as_right(thingyB_id id, T&& func) const {
			if(bool(id)) {
				for(auto list_pos = relate_in_list.m_head_back_right.vptr()[id.index()]; bool(list_pos); list_pos = relate_in_list.m_link_right.vptr()[list_pos.index()].right) {
					func(list_pos);
				}
			}
		}
		void thingyB_remove_all_relate_in_list_as_right(thingyB_id id) noexcept {
			dcon::local_vector<relate_in_list_id> temp;
			thingyB_for_each_relate_in_list_as_right(id, [&](relate_in_list_id j) { temp.push_back(j); });
			std::for_each(temp.begin(), temp.end(), [t = this](relate_in_list_id i) { t->delete_relate_in_list(i); });
		}
		
		template<typename T>
		DCON_RELEASE_INLINE void thingyB_for_each_relate_in_list(thingyB_id id, T&& func) const {
			if(bool(id)) {
				for(auto list_pos = relate_in_list.m_head_back_right.vptr()[id.index()]; bool(list_pos); list_pos = relate_in_list.m_link_right.vptr()[list_pos.index()].right) {
					func(list_pos);
				}
			}
		}
		void thingyB_remove_all_relate_in_list(thingyB_id id) noexcept {
			dcon::local_vector<relate_in_list_id> temp;
			thingyB_for_each_relate_in_list_as_right(id, [&](relate_in_list_id j) { temp.push_back(j); });
			std::for_each(temp.begin(), temp.end(), [t = this](relate_in_list_id i) { t->delete_relate_in_list(i); });
		}
		

		//
		// convenience getters and setters that operate via an implcit join
		//
		
		//
		// convenience getters and setters that operate via an implcit join
		//
		template<typename T>
		void thingyB_for_each_left_from_relate_in_array(thingyB_id id, T&& func) const {
			thingyB_for_each_relate_in_array_as_right(id, [&](relate_in_array_id i) {
				func(relate_in_array_get_left(i));
			} );
		}
		bool thingyB_has_left_from_relate_in_array(thingyB_id id, thingyA_id const& target) const {
			auto vrange = dcon::get_range(relate_in_array.right_storage, relate_in_array.m_array_right.vptr()[id.index()]);
			for(auto pos = vrange.first; pos != vrange.second; ++pos) {
				if(pos->index() == target.index()) return true;
			}
			return false;
		}
		thingyB_id thingyA_get_right_from_relate_in_array(thingyA_id ref_id) const {
			return relate_in_array_get_right(relate_in_array_id(relate_in_array_id::value_base_t(ref_id.index())));
		}
		#ifndef DCON_NO_VE
		ve::value_to_vector_type<thingyB_id> thingyA_get_right_from_relate_in_array(ve::contiguous_tags<thingyA_id> ref_id) const {
			return relate_in_array_get_right(ve::contiguous_tags<relate_in_array_id>(ref_id.value));
		}
		ve::value_to_vector_type<thingyB_id> thingyA_get_right_from_relate_in_array(ve::partial_contiguous_tags<thingyA_id> ref_id) const {
			return relate_in_array_get_right(ve::partial_contiguous_tags<relate_in_array_id>(ref_id.value, ref_id.subcount));
		}
		ve::value_to_vector_type<thingyB_id> thingyA_get_right_from_relate_in_array(ve::tagged_vector<thingyA_id> ref_id) const {
			return relate_in_array_get_right(ve::tagged_vector<relate_in_array_id>(ref_id, std::true_type{}));
		}
		#endif
		void thingyA_set_right_from_relate_in_array(thingyA_id ref_id, thingyB_id val) {
			relate_in_array_set_right(relate_in_array_id(relate_in_array_id::value_base_t(ref_id.index())), val);
		}
		
		//
		// convenience getters and setters that operate via an implcit join
		//
		template<typename T>
		void thingyB_for_each_left_from_relate_in_list(thingyB_id id, T&& func) const {
			thingyB_for_each_relate_in_list_as_right(id, [&](relate_in_list_id i) {
				func(relate_in_list_get_left(i));
			} );
		}
		bool thingyB_has_left_from_relate_in_list(thingyB_id id, thingyA_id const& target) const {
			for(auto list_pos = relate_in_list.m_head_back_right.vptr()[id.index()]; bool(list_pos); list_pos = relate_in_list.m_link_right.vptr()[list_pos.index()].right) {
				if(list_pos.index() == target.index()) return true;
			}
			return false;
		}
		thingyB_id thingyA_get_right_from_relate_in_list(thingyA_id ref_id) const {
			return relate_in_list_get_right(relate_in_list_id(relate_in_list_id::value_base_t(ref_id.index())));
		}
		#ifndef DCON_NO_VE
		ve::value_to_vector_type<thingyB_id> thingyA_get_right_from_relate_in_list(ve::contiguous_tags<thingyA_id> ref_id) const {
			return relate_in_list_get_right(ve::contiguous_tags<relate_in_list_id>(ref_id.value));
		}
		ve::value_to_vector_type<thingyB_id> thingyA_get_right_from_relate_in_list(ve::partial_contiguous_tags<thingyA_id> ref_id) const {
			return relate_in_list_get_right(ve::partial_contiguous_tags<relate_in_list_id>(ref_id.value, ref_id.subcount));
		}
		ve::value_to_vector_type<thingyB_id> thingyA_get_right_from_relate_in_list(ve::tagged_vector<thingyA_id> ref_id) const {
			return relate_in_list_get_right(ve::tagged_vector<relate_in_list_id>(ref_id, std::true_type{}));
		}
		#endif
		void thingyA_set_right_from_relate_in_list(thingyA_id ref_id, thingyB_id val) {
			relate_in_list_set_right(relate_in_list_id(relate_in_list_id::value_base_t(ref_id.index())), val);
		}
		
		//
		// container pop_back for thingyA
		//
		void pop_back_thingyA() {
			if(thingyA.size_used == 0) return;
			thingyA_id id_removed(thingyA_id::value_base_t(thingyA.size_used - 1));
			delete_relate_same(relate_same_id(relate_same_id::value_base_t(id_removed.index())));
			relate_same.size_used = thingyA.size_used - 1;
			delete_relate_in_array(relate_in_array_id(relate_in_array_id::value_base_t(id_removed.index())));
			relate_in_array.size_used = thingyA.size_used - 1;
			delete_relate_in_list(relate_in_list_id(relate_in_list_id::value_base_t(id_removed.index())));
			relate_in_list.size_used = thingyA.size_used - 1;
			thingyA.m_some_value.vptr()[id_removed.index()] = int32_t{};
			--thingyA.size_used;
		}
		
		//
		// container resize for thingyA
		//
		void thingyA_resize(uint32_t new_size) {
			#ifndef DCON_USE_EXCEPTIONS
			if(new_size > 1200) std::abort();
			#else
			if(new_size > 1200) throw dcon::out_of_space{};
			#endif
			const uint32_t old_size = thingyA.size_used;
			if(new_size < old_size) {
				std::fill_n(thingyA.m_some_value.vptr() + new_size, old_size - new_size, int32_t{});
				relate_same_resize(std::min(new_size, relate_same.size_used));
				relate_in_array_resize(std::min(new_size, relate_in_array.size_used));
				relate_in_list_resize(std::min(new_size, relate_in_list.size_used));
			} else if(new_size > old_size) {
			}
			thingyA.size_used = new_size;
		}
		
		//
		// container create for thingyA
		//
		thingyA_id create_thingyA() {
			thingyA_id new_id(thingyA_id::value_base_t(thingyA.size_used));
			#ifndef DCON_USE_EXCEPTIONS
			if(thingyA.size_used >= 1200) std::abort();
			#else
			if(thingyA.size_used >= 1200) throw dcon::out_of_space{};
			#endif
			relate_same.size_used = thingyA.size_used + 1;
			relate_in_array.size_used = thingyA.size_used + 1;
			relate_in_list.size_used = thingyA.size_used + 1;
			++thingyA.size_used;
			return new_id;
		}
		
		//
		// container compactable delete for thingyA
		//
		void delete_thingyA(thingyA_id id) {
			thingyA_id id_removed = id;
			thingyA_id last_id(thingyA_id::value_base_t(thingyA.size_used - 1));
			if(id_removed == last_id) { pop_back_thingyA(); return; }
			delete_relate_same(relate_same_id(relate_same_id::value_base_t(id_removed.index())));
			internal_move_relationship_relate_same(relate_same_id(relate_same_id::value_base_t(last_id.index())), relate_same_id(relate_same_id::value_base_t(id_removed.index())));
			relate_same.size_used = thingyA.size_used - 1;
			delete_relate_in_array(relate_in_array_id(relate_in_array_id::value_base_t(id_removed.index())));
			internal_move_relationship_relate_in_array(relate_in_array_id(relate_in_array_id::value_base_t(last_id.index())), relate_in_array_id(relate_in_array_id::value_base_t(id_removed.index())));
			relate_in_array.size_used = thingyA.size_used - 1;
			delete_relate_in_list(relate_in_list_id(relate_in_list_id::value_base_t(id_removed.index())));
			internal_move_relationship_relate_in_list(relate_in_list_id(relate_in_list_id::value_base_t(last_id.index())), relate_in_list_id(relate_in_list_id::value_base_t(id_removed.index())));
			relate_in_list.size_used = thingyA.size_used - 1;
			thingyA.m_some_value.vptr()[id_removed.index()] = std::move(thingyA.m_some_value.vptr()[last_id.index()]);
			thingyA.m_some_value.vptr()[last_id.index()] = int32_t{};
			--thingyA.size_used;
		}
		
		bool thingyA_is_valid(thingyA_id id) const {
			return bool(id) && uint32_t(id.index()) < thingyA.size_used;
		}
		//
		// container delete for thingyB
		//
		void delete_thingyB(thingyB_id id_removed) {
			if(!thingyB_is_valid(id_removed)) return;
			thingyB.m__index.vptr()[id_removed.index()] = thingyB.first_free;
			thingyB.first_free = id_removed;
			if(int32_t(thingyB.size_used) - 1 == id_removed.index()) {
				for( ; thingyB.size_used > 0 && thingyB.m__index.vptr()[thingyB.size_used - 1] != thingyB_id(thingyB_id::value_base_t(thingyB.size_used - 1));  --thingyB.size_used) ;
			}
			thingyB_remove_all_relate_in_array_as_right(id_removed);
			thingyB_remove_all_relate_in_list_as_right(id_removed);
			thingyB.m_some_value.vptr()[id_removed.index()] = int32_t{};
		}
		
		//
		// container create for thingyB
		//
		thingyB_id create_thingyB() {
			#ifndef DCON_USE_EXCEPTIONS
			if(!bool(thingyB.first_free)) std::abort();
			#else
			if(!bool(thingyB.first_free)) throw dcon::out_of_space{};
			#endif
			thingyB_id new_id = thingyB.first_free;
			thingyB.first_free = thingyB.m__index.vptr()[thingyB.first_free.index()];
			thingyB.m__index.vptr()[new_id.index()] = new_id;
			thingyB.size_used = std::max(thingyB.size_used, uint32_t(new_id.index() + 1));
			return new_id;
		}
		
		//
		// container resize for thingyB
		//
		void thingyB_resize(uint32_t new_size) {
			#ifndef DCON_USE_EXCEPTIONS
			if(new_size > 1200) std::abort();
			#else
			if(new_size > 1200) throw dcon::out_of_space{};
			#endif
			const uint32_t old_size = thingyB.size_used;
			if(new_size < old_size) {
				thingyB.first_free = thingyB_id();
				int32_t i = int32_t(1200 - 1);
				for(; i >= int32_t(new_size); --i) {
					thingyB.m__index.vptr()[i] = thingyB.first_free;
					thingyB.first_free = thingyB_id(thingyB_id::value_base_t(i));
				}
				for(; i >= 0; --i) {
					if(thingyB.m__index.vptr()[i] != thingyB_id(thingyB_id::value_base_t(i))) {
						thingyB.m__index.vptr()[i] = thingyB.first_free;
						thingyB.first_free = thingyB_id(thingyB_id::value_base_t(i));
					}
				}
				std::fill_n(thingyB.m_some_value.vptr() + new_size, old_size - new_size, int32_t{});
				relate_in_array_resize(0);
				relate_in_list_resize(0);
			} else if(new_size > old_size) {
				thingyB.first_free = thingyB_id();
				int32_t i = int32_t(1200 - 1);
				for(; i >= int32_t(old_size); --i) {
					thingyB.m__index.vptr()[i] = thingyB.first_free;
					thingyB.first_free = thingyB_id(thingyB_id::value_base_t(i));
				}
				for(; i >= 0; --i) {
					if(thingyB.m__index.vptr()[i] != thingyB_id(thingyB_id::value_base_t(i))) {
						thingyB.m__index.vptr()[i] = thingyB.first_free;
						thingyB.first_free = thingyB_id(thingyB_id::value_base_t(i));
					}
				}
			}
			thingyB.size_used = new_size;
		}
		
		bool thingyB_is_valid(thingyB_id id) const {
			return bool(id) && uint32_t(id.index()) < thingyB.size_used && thingyB.m__index.vptr()[id.index()] == id;
		}
		//
		// container resize for relate_same
		//
		void relate_same_resize(uint32_t new_size) {
			#ifndef DCON_USE_EXCEPTIONS
			if(new_size > 1200) std::abort();
			#else
			if(new_size > 1200) throw dcon::out_of_space{};
			#endif
			const uint32_t old_size = relate_same.size_used;
			if(new_size < old_size) {
				std::fill_n(relate_same.m_right.vptr() + 0, old_size, thingyA_id{});
			} else if(new_size > old_size) {
			}
			relate_same.size_used = new_size;
		}
		
		//
		// container delete for relate_same
		//
		void delete_relate_same(relate_same_id id_removed) {
			relate_same_set_right(id_removed, thingyA_id());
		}
		
		//
		// container pop_back for relate_same
		//
		void pop_back_relate_same() {
			if(relate_same.size_used == 0) return;
			relate_same_id id_removed(relate_same_id::value_base_t(relate_same.size_used - 1));
			relate_same_set_right(id_removed, thingyA_id());
			--relate_same.size_used;
		}
		
		bool relate_same_is_valid(relate_same_id id) const {
			return bool(id) && uint32_t(id.index()) < relate_same.size_used && thingyA_is_valid(thingyA_id(thingyA_id::value_base_t(id.index()))) && (bool(relate_same.m_right.vptr()[id.index()]) || false);
		}
		private:
		//
		// container move relationship for relate_same
		//
		void internal_move_relationship_relate_same(relate_same_id last_id, relate_same_id id_removed) {
			relate_same_set_right(id_removed, thingyA_id());
			relate_same.m_right.vptr()[id_removed.index()] = std::move(relate_same.m_right.vptr()[last_id.index()]);
			relate_same.m_right.vptr()[last_id.index()] = thingyA_id();
		}
		
		public:
		//
		// container try create relationship for relate_same
		//
		relate_same_id try_create_relate_same(thingyA_id left_p, thingyA_id right_p) {
			if(!bool(left_p)) return relate_same_id();
			if(relate_same_is_valid(relate_same_id(relate_same_id::value_base_t(left_p.index())))) return relate_same_id();
			if(!bool(right_p)) return relate_same_id();
			relate_same_id new_id(relate_same_id::value_base_t(left_p.index()));
			if(relate_same.size_used < uint32_t(left_p.value)) relate_same_resize(uint32_t(left_p.value));
			relate_same_set_right(new_id, right_p);
			return new_id;
		}
		
		//
		// container force create relationship for relate_same
		//
		relate_same_id force_create_relate_same(thingyA_id left_p, thingyA_id right_p) {
			relate_same_id new_id(relate_same_id::value_base_t(left_p.index()));
			if(relate_same.size_used < uint32_t(left_p.value)) relate_same_resize(uint32_t(left_p.value));
			relate_same_set_right(new_id, right_p);
			return new_id;
		}
		
		//
		// container resize for relate_in_array
		//
		void relate_in_array_resize(uint32_t new_size) {
			#ifndef DCON_USE_EXCEPTIONS
			if(new_size > 1200) std::abort();
			#else
			if(new_size > 1200) throw dcon::out_of_space{};
			#endif
			const uint32_t old_size = relate_in_array.size_used;
			if(new_size < old_size) {
				std::fill_n(relate_in_array.m_right.vptr() + 0, old_size, thingyB_id{});
				std::for_each(relate_in_array.m_array_right.vptr() + 0, relate_in_array.m_array_right.vptr() + 0 + thingyB.size_used, [t = this](dcon::stable_mk_2_tag& i){ t->relate_in_array.right_storage.release(i); });
			} else if(new_size > old_size) {
			}
			relate_in_array.size_used = new_size;
		}
		
		//
		// container delete for relate_in_array
		//
		void delete_relate_in_array(relate_in_array_id id_removed) {
			relate_in_array_set_right(id_removed, thingyB_id());
		}
		
		//
		// container pop_back for relate_in_array
		//
		void pop_back_relate_in_array() {
			if(relate_in_array.size_used == 0) return;
			relate_in_array_id id_removed(relate_in_array_id::value_base_t(relate_in_array.size_used - 1));
			relate_in_array_set_right(id_removed, thingyB_id());
			--relate_in_array.size_used;
		}
		
		bool relate_in_array_is_valid(relate_in_array_id id) const {
			return bool(id) && uint32_t(id.index()) < relate_in_array.size_used && thingyA_is_valid(thingyA_id(thingyA_id::value_base_t(id.index()))) && (bool(relate_in_array.m_right.vptr()[id.index()]) || false);
		}
		private:
		//
		// container move relationship for relate_in_array
		//
		void internal_move_relationship_relate_in_array(relate_in_array_id last_id, relate_in_array_id id_removed) {
			relate_in_array_set_right(id_removed, thingyB_id());
			if(auto tmp = relate_in_array.m_right.vptr()[last_id.index()]; bool(tmp)) {
				dcon::replace_unique_item(relate_in_array.right_storage, relate_in_array.m_array_right.vptr()[tmp.index()], last_id, id_removed);
			}
			relate_in_array.m_right.vptr()[id_removed.index()] = std::move(relate_in_array.m_right.vptr()[last_id.index()]);
			relate_in_array.m_right.vptr()[last_id.index()] = thingyB_id();
		}
		
		public:
		//
		// container try create relationship for relate_in_array
		//
		relate_in_array_id try_create_relate_in_array(thingyA_id left_p, thingyB_id right_p) {
			if(!bool(left_p)) return relate_in_array_id();
			if(relate_in_array_is_valid(relate_in_array_id(relate_in_array_id::value_base_t(left_p.index())))) return relate_in_array_id();
			if(!bool(right_p)) return relate_in_array_id();
			relate_in_array_id new_id(relate_in_array_id::value_base_t(left_p.index()));
			if(relate_in_array.size_used < uint32_t(left_p.value)) relate_in_array_resize(uint32_t(left_p.value));
			relate_in_array_set_right(new_id, right_p);
			return new_id;
		}
		
		//
		// container force create relationship for relate_in_array
		//
		relate_in_array_id force_create_relate_in_array(thingyA_id left_p, thingyB_id right_p) {
			relate_in_array_id new_id(relate_in_array_id::value_base_t(left_p.index()));
			if(relate_in_array.size_used < uint32_t(left_p.value)) relate_in_array_resize(uint32_t(left_p.value));
			relate_in_array_set_right(new_id, right_p);
			return new_id;
		}
		
		//
		// container resize for relate_in_list
		//
		void relate_in_list_resize(uint32_t new_size) {
			#ifndef DCON_USE_EXCEPTIONS
			if(new_size > 1200) std::abort();
			#else
			if(new_size > 1200) throw dcon::out_of_space{};
			#endif
			const uint32_t old_size = relate_in_list.size_used;
			if(new_size < old_size) {
				std::fill_n(relate_in_list.m_right.vptr() + 0, old_size, thingyB_id{});
				std::fill_n(relate_in_list.m_link_right.vptr() + 0, old_size, relate_in_list_id_pair{});
				std::fill_n(relate_in_list.m_head_back_right.vptr() + 0, thingyB.size_used, relate_in_list_id{});
			} else if(new_size > old_size) {
			}
			relate_in_list.size_used = new_size;
		}
		
		//
		// container delete for relate_in_list
		//
		void delete_relate_in_list(relate_in_list_id id_removed) {
			relate_in_list_set_right(id_removed, thingyB_id());
		}
		
		//
		// container pop_back for relate_in_list
		//
		void pop_back_relate_in_list() {
			if(relate_in_list.size_used == 0) return;
			relate_in_list_id id_removed(relate_in_list_id::value_base_t(relate_in_list.size_used - 1));
			relate_in_list_set_right(id_removed, thingyB_id());
			--relate_in_list.size_used;
		}
		
		bool relate_in_list_is_valid(relate_in_list_id id) const {
			return bool(id) && uint32_t(id.index()) < relate_in_list.size_used && thingyA_is_valid(thingyA_id(thingyA_id::value_base_t(id.index()))) && (bool(relate_in_list.m_right.vptr()[id.index()]) || false);
		}
		private:
		//
		// container move relationship for relate_in_list
		//
		void internal_move_relationship_relate_in_list(relate_in_list_id last_id, relate_in_list_id id_removed) {
			relate_in_list_set_right(id_removed, thingyB_id());
			if(bool(relate_in_list.m_right.vptr()[last_id.index()])) {
				auto tmp = relate_in_list.m_link_right.vptr()[last_id.index()];
				if(bool(tmp.left)) {
					relate_in_list.m_link_right.vptr()[tmp.left.index()].right = id_removed;
				} else {
					for(auto lpos = last_id; bool(lpos); lpos = relate_in_list.m_link_right.vptr()[lpos.index()].right) {
						relate_in_list.m_head_back_right.vptr()[relate_in_list.m_right.vptr()[lpos.index()].index()] = id_removed;
					}
				}
				if(bool(tmp.right)) {
					relate_in_list.m_link_right.vptr()[tmp.right.index()].left = id_removed;
				}
			}
			relate_in_list.m_link_right.vptr()[id_removed.index()] = std::move(relate_in_list.m_link_right.vptr()[last_id.index()]);
			relate_in_list.m_link_right.vptr()[last_id.index()] = relate_in_list_id_pair();
			relate_in_list.m_right.vptr()[id_removed.index()] = std::move(relate_in_list.m_right.vptr()[last_id.index()]);
			relate_in_list.m_right.vptr()[last_id.index()] = thingyB_id();
		}
		
		public:
		//
		// container try create relationship for relate_in_list
		//
		relate_in_list_id try_create_relate_in_list(thingyA_id left_p, thingyB_id right_p) {
			if(!bool(left_p)) return relate_in_list_id();
			if(relate_in_list_is_valid(relate_in_list_id(relate_in_list_id::value_base_t(left_p.index())))) return relate_in_list_id();
			if(!bool(right_p)) return relate_in_list_id();
			relate_in_list_id new_id(relate_in_list_id::value_base_t(left_p.index()));
			if(relate_in_list.size_used < uint32_t(left_p.value)) relate_in_list_resize(uint32_t(left_p.value));
			relate_in_list_set_right(new_id, right_p);
			return new_id;
		}
		
		//
		// container force create relationship for relate_in_list
		//
		relate_in_list_id force_create_relate_in_list(thingyA_id left_p, thingyB_id right_p) {
			relate_in_list_id new_id(relate_in_list_id::value_base_t(left_p.index()));
			if(relate_in_list.size_used < uint32_t(left_p.value)) relate_in_list_resize(uint32_t(left_p.value));
			relate_in_list_set_right(new_id, right_p);
			return new_id;
		}
		
		template <typename T>
		DCON_RELEASE_INLINE void for_each_thingyA(T&& func) {
			for(uint32_t i = 0; i < thingyA.size_used; ++i) {
				thingyA_id tmp(thingyA_id::value_base_t(i));
				func(tmp);
			}
		}
		
		template <typename T>
		DCON_RELEASE_INLINE void for_each_thingyB(T&& func) {
			for(uint32_t i = 0; i < thingyB.size_used; ++i) {
				thingyB_id tmp(thingyB_id::value_base_t(i));
				if(thingyB.m__index.vptr()[tmp.index()] == tmp) func(tmp);
			}
		}
		
		template <typename T>
		DCON_RELEASE_INLINE void for_each_relate_same(T&& func) {
			for(uint32_t i = 0; i < relate_same.size_used; ++i) {
				relate_same_id tmp(relate_same_id::value_base_t(i));
				func(tmp);
			}
		}
		
		template <typename T>
		DCON_RELEASE_INLINE void for_each_relate_in_array(T&& func) {
			for(uint32_t i = 0; i < relate_in_array.size_used; ++i) {
				relate_in_array_id tmp(relate_in_array_id::value_base_t(i));
				func(tmp);
			}
		}
		
		template <typename T>
		DCON_RELEASE_INLINE void for_each_relate_in_list(T&& func) {
			for(uint32_t i = 0; i < relate_in_list.size_used; ++i) {
				relate_in_list_id tmp(relate_in_list_id::value_base_t(i));
				func(tmp);
			}
		}
		


		void reset() {
			relate_same_resize(0);
			relate_in_array_resize(0);
			relate_in_list_resize(0);
			thingyA_resize(0);
			thingyB_resize(0);
		}

		#ifndef DCON_NO_VE
		ve::vectorizable_buffer<float, thingyA_id> thingyA_make_vectorizable_float_buffer() const noexcept {
			return ve::vectorizable_buffer<float, thingyA_id>(thingyA.size_used);
		}
		ve::vectorizable_buffer<int32_t, thingyA_id> thingyA_make_vectorizable_int_buffer() const noexcept {
			return ve::vectorizable_buffer<int32_t, thingyA_id>(thingyA.size_used);
		}
		template<typename F>
		DCON_RELEASE_INLINE void execute_serial_over_thingyA(F&& functor) {
			ve::execute_serial(thingyA.size_used, functor);
		}
#ifndef VE_NO_TBB
		template<typename F>
		DCON_RELEASE_INLINE void execute_parallel_over_thingyA(F&& functor) {
			ve::execute_parallel_exact(thingyA.size_used, functor);
		}
#endif
		ve::vectorizable_buffer<float, thingyB_id> thingyB_make_vectorizable_float_buffer() const noexcept {
			return ve::vectorizable_buffer<float, thingyB_id>(thingyB.size_used);
		}
		ve::vectorizable_buffer<int32_t, thingyB_id> thingyB_make_vectorizable_int_buffer() const noexcept {
			return ve::vectorizable_buffer<int32_t, thingyB_id>(thingyB.size_used);
		}
		template<typename F>
		DCON_RELEASE_INLINE void execute_serial_over_thingyB(F&& functor) {
			ve::execute_serial(thingyB.size_used, functor);
		}
#ifndef VE_NO_TBB
		template<typename F>
		DCON_RELEASE_INLINE void execute_parallel_over_thingyB(F&& functor) {
			ve::execute_parallel_exact(thingyB.size_used, functor);
		}
#endif
		ve::vectorizable_buffer<float, relate_same_id> relate_same_make_vectorizable_float_buffer() const noexcept {
			return ve::vectorizable_buffer<float, relate_same_id>(relate_same.size_used);
		}
		ve::vectorizable_buffer<int32_t, relate_same_id> relate_same_make_vectorizable_int_buffer() const noexcept {
			return ve::vectorizable_buffer<int32_t, relate_same_id>(relate_same.size_used);
		}
		template<typename F>
		DCON_RELEASE_INLINE void execute_serial_over_relate_same(F&& functor) {
			ve::execute_serial(relate_same.size_used, functor);
		}
#ifndef VE_NO_TBB
		template<typename F>
		DCON_RELEASE_INLINE void execute_parallel_over_relate_same(F&& functor) {
			ve::execute_parallel_exact(relate_same.size_used, functor);
		}
#endif
		ve::vectorizable_buffer<float, relate_in_array_id> relate_in_array_make_vectorizable_float_buffer() const noexcept {
			return ve::vectorizable_buffer<float, relate_in_array_id>(relate_in_array.size_used);
		}
		ve::vectorizable_buffer<int32_t, relate_in_array_id> relate_in_array_make_vectorizable_int_buffer() const noexcept {
			return ve::vectorizable_buffer<int32_t, relate_in_array_id>(relate_in_array.size_used);
		}
		template<typename F>
		DCON_RELEASE_INLINE void execute_serial_over_relate_in_array(F&& functor) {
			ve::execute_serial(relate_in_array.size_used, functor);
		}
#ifndef VE_NO_TBB
		template<typename F>
		DCON_RELEASE_INLINE void execute_parallel_over_relate_in_array(F&& functor) {
			ve::execute_parallel_exact(relate_in_array.size_used, functor);
		}
#endif
		ve::vectorizable_buffer<float, relate_in_list_id> relate_in_list_make_vectorizable_float_buffer() const noexcept {
			return ve::vectorizable_buffer<float, relate_in_list_id>(relate_in_list.size_used);
		}
		ve::vectorizable_buffer<int32_t, relate_in_list_id> relate_in_list_make_vectorizable_int_buffer() const noexcept {
			return ve::vectorizable_buffer<int32_t, relate_in_list_id>(relate_in_list.size_used);
		}
		template<typename F>
		DCON_RELEASE_INLINE void execute_serial_over_relate_in_list(F&& functor) {
			ve::execute_serial(relate_in_list.size_used, functor);
		}
#ifndef VE_NO_TBB
		template<typename F>
		DCON_RELEASE_INLINE void execute_parallel_over_relate_in_list(F&& functor) {
			ve::execute_parallel_exact(relate_in_list.size_used, functor);
		}
#endif
		#endif

		load_record serialize_entire_container_record() const noexcept {
			load_record result;
			result.thingyA = true;
			result.thingyA_some_value = true;
			result.thingyB = true;
			result.thingyB__index = true;
			result.thingyB_some_value = true;
			result.relate_same = true;
			result.relate_same_left = true;
			result.relate_same_right = true;
			result.relate_in_array = true;
			result.relate_in_array_left = true;
			result.relate_in_array_right = true;
			result.relate_in_list = true;
			result.relate_in_list_left = true;
			result.relate_in_list_right = true;
			return result;
		}
		
		//
		// calculate size (in bytes) required to serialize the desired objects, relationships, and properties
		//
		uint64_t serialize_size(load_record const& serialize_selection) const {
			uint64_t total_size = 0;
			if(serialize_selection.thingyA) {
				dcon::record_header header(0, "uint32_t", "thingyA", "$size");
				total_size += header.serialize_size();
				total_size += sizeof(uint32_t);
			}
			if(serialize_selection.thingyA_some_value) {
				dcon::record_header iheader(0, "int32_t", "thingyA", "some_value");
				total_size += iheader.serialize_size();
				total_size += sizeof(int32_t) * thingyA.size_used;
			}
			if(serialize_selection.thingyB) {
				dcon::record_header header(0, "uint32_t", "thingyB", "$size");
				total_size += header.serialize_size();
				total_size += sizeof(uint32_t);
			}
			if(serialize_selection.thingyB__index) {
				dcon::record_header iheader(0, "uint16_t", "thingyB", "_index");
				total_size += iheader.serialize_size();
				total_size += sizeof(thingyB_id) * thingyB.size_used;
			}
			if(serialize_selection.thingyB_some_value) {
				dcon::record_header iheader(0, "int32_t", "thingyB", "some_value");
				total_size += iheader.serialize_size();
				total_size += sizeof(int32_t) * thingyB.size_used;
			}
			if(serialize_selection.relate_same) {
				dcon::record_header header(0, "uint32_t", "relate_same", "$size");
				total_size += header.serialize_size();
				total_size += sizeof(uint32_t);
				if(serialize_selection.relate_same_right) {
					dcon::record_header iheader(0, "uint16_t", "relate_same", "right");
					total_size += iheader.serialize_size();
					total_size += sizeof(thingyA_id) * relate_same.size_used;
				}
				dcon::record_header headerb(0, "$", "relate_same", "$index_end");
				total_size += headerb.serialize_size();
			}
			if(serialize_selection.relate_in_array) {
				dcon::record_header header(0, "uint32_t", "relate_in_array", "$size");
				total_size += header.serialize_size();
				total_size += sizeof(uint32_t);
				if(serialize_selection.relate_in_array_right) {
					dcon::record_header iheader(0, "uint16_t", "relate_in_array", "right");
					total_size += iheader.serialize_size();
					total_size += sizeof(thingyB_id) * relate_in_array.size_used;
				}
				dcon::record_header headerb(0, "$", "relate_in_array", "$index_end");
				total_size += headerb.serialize_size();
			}
			if(serialize_selection.relate_in_list) {
				dcon::record_header header(0, "uint32_t", "relate_in_list", "$size");
				total_size += header.serialize_size();
				total_size += sizeof(uint32_t);
				if(serialize_selection.relate_in_list_right) {
					dcon::record_header iheader(0, "uint16_t", "relate_in_list", "right");
					total_size += iheader.serialize_size();
					total_size += sizeof(thingyB_id) * relate_in_list.size_used;
				}
				dcon::record_header headerb(0, "$", "relate_in_list", "$index_end");
				total_size += headerb.serialize_size();
			}
			return total_size;
		}
		
		//
		// serialize the desired objects, relationships, and properties
		//
		void serialize(std::byte*& output_buffer, load_record const& serialize_selection) const {
			if(serialize_selection.thingyA) {
				dcon::record_header header(sizeof(uint32_t), "uint32_t", "thingyA", "$size");
				header.serialize(output_buffer);
				*(reinterpret_cast<uint32_t*>(output_buffer)) = thingyA.size_used;
				output_buffer += sizeof(uint32_t);
			}
			if(serialize_selection.thingyA_some_value) {
				dcon::record_header header(sizeof(int32_t) * thingyA.size_used, "int32_t", "thingyA", "some_value");
				header.serialize(output_buffer);
				std::memcpy(reinterpret_cast<int32_t*>(output_buffer), thingyA.m_some_value.vptr(), sizeof(int32_t) * thingyA.size_used);
				output_buffer += sizeof(int32_t) * thingyA.size_used;
			}
			if(serialize_selection.thingyB) {
				dcon::record_header header(sizeof(uint32_t), "uint32_t", "thingyB", "$size");
				header.serialize(output_buffer);
				*(reinterpret_cast<uint32_t*>(output_buffer)) = thingyB.size_used;
				output_buffer += sizeof(uint32_t);
			}
			if(serialize_selection.thingyB__index) {
				dcon::record_header header(sizeof(thingyB_id) * thingyB.size_used, "uint16_t", "thingyB", "_index");
				header.serialize(output_buffer);
				std::memcpy(reinterpret_cast<thingyB_id*>(output_buffer), thingyB.m__index.vptr(), sizeof(thingyB_id) * thingyB.size_used);
				output_buffer += sizeof(thingyB_id) * thingyB.size_used;
			}
			if(serialize_selection.thingyB_some_value) {
				dcon::record_header header(sizeof(int32_t) * thingyB.size_used, "int32_t", "thingyB", "some_value");
				header.serialize(output_buffer);
				std::memcpy(reinterpret_cast<int32_t*>(output_buffer), thingyB.m_some_value.vptr(), sizeof(int32_t) * thingyB.size_used);
				output_buffer += sizeof(int32_t) * thingyB.size_used;
			}
			if(serialize_selection.relate_same) {
				dcon::record_header header(sizeof(uint32_t), "uint32_t", "relate_same", "$size");
				header.serialize(output_buffer);
				*(reinterpret_cast<uint32_t*>(output_buffer)) = relate_same.size_used;
				output_buffer += sizeof(uint32_t);
				{
					dcon::record_header iheader(sizeof(thingyA_id) * relate_same.size_used, "uint16_t", "relate_same", "right");
					iheader.serialize(output_buffer);
					std::memcpy(reinterpret_cast<thingyA_id*>(output_buffer), relate_same.m_right.vptr(), sizeof(thingyA_id) * relate_same.size_used);
					output_buffer += sizeof(thingyA_id) * relate_same.size_used;
				}
				dcon::record_header headerb(0, "$", "relate_same", "$index_end");
				headerb.serialize(output_buffer);
			}
			if(serialize_selection.relate_in_array) {
				dcon::record_header header(sizeof(uint32_t), "uint32_t", "relate_in_array", "$size");
				header.serialize(output_buffer);
				*(reinterpret_cast<uint32_t*>(output_buffer)) = relate_in_array.size_used;
				output_buffer += sizeof(uint32_t);
				{
					dcon::record_header iheader(sizeof(thingyB_id) * relate_in_array.size_used, "uint16_t", "relate_in_array", "right");
					iheader.serialize(output_buffer);
					std::memcpy(reinterpret_cast<thingyB_id*>(output_buffer), relate_in_array.m_right.vptr(), sizeof(thingyB_id) * relate_in_array.size_used);
					output_buffer += sizeof(thingyB_id) * relate_in_array.size_used;
				}
				dcon::record_header headerb(0, "$", "relate_in_array", "$index_end");
				headerb.serialize(output_buffer);
			}
			if(serialize_selection.relate_in_list) {
				dcon::record_header header(sizeof(uint32_t), "uint32_t", "relate_in_list", "$size");
				header.serialize(output_buffer);
				*(reinterpret_cast<uint32_t*>(output_buffer)) = relate_in_list.size_used;
				output_buffer += sizeof(uint32_t);
				{
					dcon::record_header iheader(sizeof(thingyB_id) * relate_in_list.size_used, "uint16_t", "relate_in_list", "right");
					iheader.serialize(output_buffer);
					std::memcpy(reinterpret_cast<thingyB_id*>(output_buffer), relate_in_list.m_right.vptr(), sizeof(thingyB_id) * relate_in_list.size_used);
					output_buffer += sizeof(thingyB_id) * relate_in_list.size_used;
				}
				dcon::record_header headerb(0, "$", "relate_in_list", "$index_end");
				headerb.serialize(output_buffer);
			}
		}
		
		//
		// deserialize the desired objects, relationships, and properties
		//
		void deserialize(std::byte const*& input_buffer, std::byte const* end, load_record& serialize_selection) {
			while(input_buffer < end) {
				dcon::record_header header;
				header.deserialize(input_buffer, end);
				if(input_buffer + header.record_size <= end) {
					if(header.is_object("thingyA")) {
						if(header.is_property("$size") && header.record_size == sizeof(uint32_t)) {
							thingyA_resize(*(reinterpret_cast<uint32_t const*>(input_buffer)));
							serialize_selection.thingyA = true;
						}
						else if(header.is_property("some_value")) {
							if(header.is_type("int32_t")) {
								std::memcpy(thingyA.m_some_value.vptr(), reinterpret_cast<int32_t const*>(input_buffer), std::min(size_t(thingyA.size_used) * sizeof(int32_t), header.record_size));
								serialize_selection.thingyA_some_value = true;
							}
							else if(header.is_type("int8_t")) {
								for(uint32_t i = 0; i < std::min(thingyA.size_used, uint32_t(header.record_size / sizeof(int8_t))); ++i) {
									thingyA.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<int8_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyA_some_value = true;
							}
							else if(header.is_type("uint8_t")) {
								for(uint32_t i = 0; i < std::min(thingyA.size_used, uint32_t(header.record_size / sizeof(uint8_t))); ++i) {
									thingyA.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<uint8_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyA_some_value = true;
							}
							else if(header.is_type("int16_t")) {
								for(uint32_t i = 0; i < std::min(thingyA.size_used, uint32_t(header.record_size / sizeof(int16_t))); ++i) {
									thingyA.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<int16_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyA_some_value = true;
							}
							else if(header.is_type("uint16_t")) {
								for(uint32_t i = 0; i < std::min(thingyA.size_used, uint32_t(header.record_size / sizeof(uint16_t))); ++i) {
									thingyA.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<uint16_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyA_some_value = true;
							}
							else if(header.is_type("uint32_t")) {
								for(uint32_t i = 0; i < std::min(thingyA.size_used, uint32_t(header.record_size / sizeof(uint32_t))); ++i) {
									thingyA.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<uint32_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyA_some_value = true;
							}
							else if(header.is_type("int64_t")) {
								for(uint32_t i = 0; i < std::min(thingyA.size_used, uint32_t(header.record_size / sizeof(int64_t))); ++i) {
									thingyA.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<int64_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyA_some_value = true;
							}
							else if(header.is_type("uint64_t")) {
								for(uint32_t i = 0; i < std::min(thingyA.size_used, uint32_t(header.record_size / sizeof(uint64_t))); ++i) {
									thingyA.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<uint64_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyA_some_value = true;
							}
							else if(header.is_type("float")) {
								for(uint32_t i = 0; i < std::min(thingyA.size_used, uint32_t(header.record_size / sizeof(float))); ++i) {
									thingyA.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<float const*>(input_buffer) + i));
								}
								serialize_selection.thingyA_some_value = true;
							}
							else if(header.is_type("double")) {
								for(uint32_t i = 0; i < std::min(thingyA.size_used, uint32_t(header.record_size / sizeof(double))); ++i) {
									thingyA.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<double const*>(input_buffer) + i));
								}
								serialize_selection.thingyA_some_value = true;
							}
						}
					} else
					if(header.is_object("thingyB")) {
						if(header.is_property("$size") && header.record_size == sizeof(uint32_t)) {
							thingyB_resize(*(reinterpret_cast<uint32_t const*>(input_buffer)));
							serialize_selection.thingyB = true;
						}
						else if(header.is_property("__index")) {
							if(header.is_type("uint16_t")) {
								std::memcpy(thingyB.m__index.vptr(), reinterpret_cast<uint16_t const*>(input_buffer), std::min(size_t(thingyB.size_used) * sizeof(uint16_t), header.record_size));
								serialize_selection.thingyB__index = true;
							}
							else if(header.is_type("uint8_t")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(uint8_t))); ++i) {
									thingyB.m__index.vptr()[i].value = uint16_t(*(reinterpret_cast<uint8_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyB__index = true;
							}
							else if(header.is_type("uint32_t")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(uint32_t))); ++i) {
									thingyB.m__index.vptr()[i].value = uint16_t(*(reinterpret_cast<uint32_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyB__index = true;
							}
							if(serialize_selection.thingyB__index == true) {
								thingyB.size_used = 0;
								thingyB.first_free = thingyB_id();
								for(int32_t j = 1200 - 1; j > 0; --j) {
									if(thingyB.m__index.vptr()[j] != thingyB_id(uint16_t(j))) {
										thingyB.m__index.vptr()[j] = thingyB.first_free;
										thingyB.first_free = thingyB_id(uint16_t(j));
									} else {
										thingyB.size_used = std::max(thingyB.size_used, uint32_t(j));
									}
								}
							}
						}
						else if(header.is_property("some_value")) {
							if(header.is_type("int32_t")) {
								std::memcpy(thingyB.m_some_value.vptr(), reinterpret_cast<int32_t const*>(input_buffer), std::min(size_t(thingyB.size_used) * sizeof(int32_t), header.record_size));
								serialize_selection.thingyB_some_value = true;
							}
							else if(header.is_type("int8_t")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(int8_t))); ++i) {
									thingyB.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<int8_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyB_some_value = true;
							}
							else if(header.is_type("uint8_t")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(uint8_t))); ++i) {
									thingyB.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<uint8_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyB_some_value = true;
							}
							else if(header.is_type("int16_t")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(int16_t))); ++i) {
									thingyB.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<int16_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyB_some_value = true;
							}
							else if(header.is_type("uint16_t")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(uint16_t))); ++i) {
									thingyB.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<uint16_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyB_some_value = true;
							}
							else if(header.is_type("uint32_t")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(uint32_t))); ++i) {
									thingyB.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<uint32_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyB_some_value = true;
							}
							else if(header.is_type("int64_t")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(int64_t))); ++i) {
									thingyB.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<int64_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyB_some_value = true;
							}
							else if(header.is_type("uint64_t")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(uint64_t))); ++i) {
									thingyB.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<uint64_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyB_some_value = true;
							}
							else if(header.is_type("float")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(float))); ++i) {
									thingyB.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<float const*>(input_buffer) + i));
								}
								serialize_selection.thingyB_some_value = true;
							}
							else if(header.is_type("double")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(double))); ++i) {
									thingyB.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<double const*>(input_buffer) + i));
								}
								serialize_selection.thingyB_some_value = true;
							}
						}
					} else
					if(header.is_object("relate_same")) {
						if(header.is_property("$size") && header.record_size == sizeof(uint32_t)) {
							if(*(reinterpret_cast<uint32_t const*>(input_buffer)) >= relate_same.size_used) {
								relate_same_resize(0);
							}
							relate_same_resize(*(reinterpret_cast<uint32_t const*>(input_buffer)));
							serialize_selection.relate_same = true;
						}
						else if(header.is_property("right")) {
							if(header.is_type("uint16_t")) {
								std::memcpy(relate_same.m_right.vptr(), reinterpret_cast<uint16_t const*>(input_buffer), std::min(size_t(relate_same.size_used) * sizeof(uint16_t), header.record_size));
								serialize_selection.relate_same_right = true;
							}
							else if(header.is_type("uint8_t")) {
								for(uint32_t i = 0; i < std::min(relate_same.size_used, uint32_t(header.record_size / sizeof(uint8_t))); ++i) {
									relate_same.m_right.vptr()[i].value = uint16_t(*(reinterpret_cast<uint8_t const*>(input_buffer) + i));
								}
								serialize_selection.relate_same_right = true;
							}
							else if(header.is_type("uint32_t")) {
								for(uint32_t i = 0; i < std::min(relate_same.size_used, uint32_t(header.record_size / sizeof(uint32_t))); ++i) {
									relate_same.m_right.vptr()[i].value = uint16_t(*(reinterpret_cast<uint32_t const*>(input_buffer) + i));
								}
								serialize_selection.relate_same_right = true;
							}
						}
						else if(header.is_property("$index_end")) {
							if(serialize_selection.relate_same_right == true) {
								for(uint32_t i = 0; i < relate_same.size_used; ++i) {
									auto tmp = relate_same.m_right.vptr()[i];
									relate_same.m_right.vptr()[i] = thingyA_id();
									relate_same_set_right(relate_same_id(relate_same_id::value_base_t(i)), tmp);
								}
							}
						}
					} else
					if(header.is_object("relate_in_array")) {
						if(header.is_property("$size") && header.record_size == sizeof(uint32_t)) {
							if(*(reinterpret_cast<uint32_t const*>(input_buffer)) >= relate_in_array.size_used) {
								relate_in_array_resize(0);
							}
							relate_in_array_resize(*(reinterpret_cast<uint32_t const*>(input_buffer)));
							serialize_selection.relate_in_array = true;
						}
						else if(header.is_property("right")) {
							if(header.is_type("uint16_t")) {
								std::memcpy(relate_in_array.m_right.vptr(), reinterpret_cast<uint16_t const*>(input_buffer), std::min(size_t(relate_in_array.size_used) * sizeof(uint16_t), header.record_size));
								serialize_selection.relate_in_array_right = true;
							}
							else if(header.is_type("uint8_t")) {
								for(uint32_t i = 0; i < std::min(relate_in_array.size_used, uint32_t(header.record_size / sizeof(uint8_t))); ++i) {
									relate_in_array.m_right.vptr()[i].value = uint16_t(*(reinterpret_cast<uint8_t const*>(input_buffer) + i));
								}
								serialize_selection.relate_in_array_right = true;
							}
							else if(header.is_type("uint32_t")) {
								for(uint32_t i = 0; i < std::min(relate_in_array.size_used, uint32_t(header.record_size / sizeof(uint32_t))); ++i) {
									relate_in_array.m_right.vptr()[i].value = uint16_t(*(reinterpret_cast<uint32_t const*>(input_buffer) + i));
								}
								serialize_selection.relate_in_array_right = true;
							}
						}
						else if(header.is_property("$index_end")) {
							if(serialize_selection.relate_in_array_right == true) {
								for(uint32_t i = 0; i < relate_in_array.size_used; ++i) {
									auto tmp = relate_in_array.m_right.vptr()[i];
									relate_in_array.m_right.vptr()[i] = thingyB_id();
									relate_in_array_set_right(relate_in_array_id(relate_in_array_id::value_base_t(i)), tmp);
								}
							}
						}
					} else
					if(header.is_object("relate_in_list")) {
						if(header.is_property("$size") && header.record_size == sizeof(uint32_t)) {
							if(*(reinterpret_cast<uint32_t const*>(input_buffer)) >= relate_in_list.size_used) {
								relate_in_list_resize(0);
							}
							relate_in_list_resize(*(reinterpret_cast<uint32_t const*>(input_buffer)));
							serialize_selection.relate_in_list = true;
						}
						else if(header.is_property("right")) {
							if(header.is_type("uint16_t")) {
								std::memcpy(relate_in_list.m_right.vptr(), reinterpret_cast<uint16_t const*>(input_buffer), std::min(size_t(relate_in_list.size_used) * sizeof(uint16_t), header.record_size));
								serialize_selection.relate_in_list_right = true;
							}
							else if(header.is_type("uint8_t")) {
								for(uint32_t i = 0; i < std::min(relate_in_list.size_used, uint32_t(header.record_size / sizeof(uint8_t))); ++i) {
									relate_in_list.m_right.vptr()[i].value = uint16_t(*(reinterpret_cast<uint8_t const*>(input_buffer) + i));
								}
								serialize_selection.relate_in_list_right = true;
							}
							else if(header.is_type("uint32_t")) {
								for(uint32_t i = 0; i < std::min(relate_in_list.size_used, uint32_t(header.record_size / sizeof(uint32_t))); ++i) {
									relate_in_list.m_right.vptr()[i].value = uint16_t(*(reinterpret_cast<uint32_t const*>(input_buffer) + i));
								}
								serialize_selection.relate_in_list_right = true;
							}
						}
						else if(header.is_property("$index_end")) {
							if(serialize_selection.relate_in_list_right == true) {
								for(uint32_t i = 0; i < relate_in_list.size_used; ++i) {
									auto tmp = relate_in_list.m_right.vptr()[i];
									relate_in_list.m_right.vptr()[i] = thingyB_id();
									relate_in_list_set_right(relate_in_list_id(relate_in_list_id::value_base_t(i)), tmp);
								}
							}
						}
					}
				}
				input_buffer += header.record_size;
			}
		}
		
		//
		// deserialize the desired objects, relationships, and properties where the mask is set
		//
		void deserialize(std::byte const*& input_buffer, std::byte const* end, load_record& serialize_selection, load_record const& mask) {
			while(input_buffer < end) {
				dcon::record_header header;
				header.deserialize(input_buffer, end);
				if(input_buffer + header.record_size <= end) {
					if(header.is_object("thingyA") && mask.thingyA) {
						if(header.is_property("$size") && header.record_size == sizeof(uint32_t)) {
							thingyA_resize(*(reinterpret_cast<uint32_t const*>(input_buffer)));
							serialize_selection.thingyA = true;
						}
						else if(header.is_property("some_value") && mask.thingyA_some_value) {
							if(header.is_type("int32_t")) {
								std::memcpy(thingyA.m_some_value.vptr(), reinterpret_cast<int32_t const*>(input_buffer), std::min(size_t(thingyA.size_used) * sizeof(int32_t), header.record_size));
								serialize_selection.thingyA_some_value = true;
							}
							else if(header.is_type("int8_t")) {
								for(uint32_t i = 0; i < std::min(thingyA.size_used, uint32_t(header.record_size / sizeof(int8_t))); ++i) {
									thingyA.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<int8_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyA_some_value = true;
							}
							else if(header.is_type("uint8_t")) {
								for(uint32_t i = 0; i < std::min(thingyA.size_used, uint32_t(header.record_size / sizeof(uint8_t))); ++i) {
									thingyA.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<uint8_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyA_some_value = true;
							}
							else if(header.is_type("int16_t")) {
								for(uint32_t i = 0; i < std::min(thingyA.size_used, uint32_t(header.record_size / sizeof(int16_t))); ++i) {
									thingyA.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<int16_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyA_some_value = true;
							}
							else if(header.is_type("uint16_t")) {
								for(uint32_t i = 0; i < std::min(thingyA.size_used, uint32_t(header.record_size / sizeof(uint16_t))); ++i) {
									thingyA.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<uint16_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyA_some_value = true;
							}
							else if(header.is_type("uint32_t")) {
								for(uint32_t i = 0; i < std::min(thingyA.size_used, uint32_t(header.record_size / sizeof(uint32_t))); ++i) {
									thingyA.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<uint32_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyA_some_value = true;
							}
							else if(header.is_type("int64_t")) {
								for(uint32_t i = 0; i < std::min(thingyA.size_used, uint32_t(header.record_size / sizeof(int64_t))); ++i) {
									thingyA.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<int64_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyA_some_value = true;
							}
							else if(header.is_type("uint64_t")) {
								for(uint32_t i = 0; i < std::min(thingyA.size_used, uint32_t(header.record_size / sizeof(uint64_t))); ++i) {
									thingyA.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<uint64_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyA_some_value = true;
							}
							else if(header.is_type("float")) {
								for(uint32_t i = 0; i < std::min(thingyA.size_used, uint32_t(header.record_size / sizeof(float))); ++i) {
									thingyA.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<float const*>(input_buffer) + i));
								}
								serialize_selection.thingyA_some_value = true;
							}
							else if(header.is_type("double")) {
								for(uint32_t i = 0; i < std::min(thingyA.size_used, uint32_t(header.record_size / sizeof(double))); ++i) {
									thingyA.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<double const*>(input_buffer) + i));
								}
								serialize_selection.thingyA_some_value = true;
							}
						}
					} else
					if(header.is_object("thingyB") && mask.thingyB) {
						if(header.is_property("$size") && header.record_size == sizeof(uint32_t)) {
							thingyB_resize(*(reinterpret_cast<uint32_t const*>(input_buffer)));
							serialize_selection.thingyB = true;
						}
						else if(header.is_property("__index") && mask.thingyB__index) {
							if(header.is_type("uint16_t")) {
								std::memcpy(thingyB.m__index.vptr(), reinterpret_cast<uint16_t const*>(input_buffer), std::min(size_t(thingyB.size_used) * sizeof(uint16_t), header.record_size));
								serialize_selection.thingyB__index = true;
							}
							else if(header.is_type("uint8_t")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(uint8_t))); ++i) {
									thingyB.m__index.vptr()[i].value = uint16_t(*(reinterpret_cast<uint8_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyB__index = true;
							}
							else if(header.is_type("uint32_t")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(uint32_t))); ++i) {
									thingyB.m__index.vptr()[i].value = uint16_t(*(reinterpret_cast<uint32_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyB__index = true;
							}
							if(serialize_selection.thingyB__index == true) {
								thingyB.size_used = 0;
								thingyB.first_free = thingyB_id();
								for(int32_t j = 1200 - 1; j > 0; --j) {
									if(thingyB.m__index.vptr()[j] != thingyB_id(uint16_t(j))) {
										thingyB.m__index.vptr()[j] = thingyB.first_free;
										thingyB.first_free = thingyB_id(uint16_t(j));
									} else {
										thingyB.size_used = std::max(thingyB.size_used, uint32_t(j));
									}
								}
							}
						}
						else if(header.is_property("some_value") && mask.thingyB_some_value) {
							if(header.is_type("int32_t")) {
								std::memcpy(thingyB.m_some_value.vptr(), reinterpret_cast<int32_t const*>(input_buffer), std::min(size_t(thingyB.size_used) * sizeof(int32_t), header.record_size));
								serialize_selection.thingyB_some_value = true;
							}
							else if(header.is_type("int8_t")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(int8_t))); ++i) {
									thingyB.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<int8_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyB_some_value = true;
							}
							else if(header.is_type("uint8_t")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(uint8_t))); ++i) {
									thingyB.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<uint8_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyB_some_value = true;
							}
							else if(header.is_type("int16_t")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(int16_t))); ++i) {
									thingyB.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<int16_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyB_some_value = true;
							}
							else if(header.is_type("uint16_t")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(uint16_t))); ++i) {
									thingyB.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<uint16_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyB_some_value = true;
							}
							else if(header.is_type("uint32_t")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(uint32_t))); ++i) {
									thingyB.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<uint32_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyB_some_value = true;
							}
							else if(header.is_type("int64_t")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(int64_t))); ++i) {
									thingyB.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<int64_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyB_some_value = true;
							}
							else if(header.is_type("uint64_t")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(uint64_t))); ++i) {
									thingyB.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<uint64_t const*>(input_buffer) + i));
								}
								serialize_selection.thingyB_some_value = true;
							}
							else if(header.is_type("float")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(float))); ++i) {
									thingyB.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<float const*>(input_buffer) + i));
								}
								serialize_selection.thingyB_some_value = true;
							}
							else if(header.is_type("double")) {
								for(uint32_t i = 0; i < std::min(thingyB.size_used, uint32_t(header.record_size / sizeof(double))); ++i) {
									thingyB.m_some_value.vptr()[i] = int32_t(*(reinterpret_cast<double const*>(input_buffer) + i));
								}
								serialize_selection.thingyB_some_value = true;
							}
						}
					} else
					if(header.is_object("relate_same") && mask.relate_same) {
						if(header.is_property("$size") && header.record_size == sizeof(uint32_t)) {
							if(*(reinterpret_cast<uint32_t const*>(input_buffer)) >= relate_same.size_used) {
								relate_same_resize(0);
							}
							relate_same_resize(*(reinterpret_cast<uint32_t const*>(input_buffer)));
							serialize_selection.relate_same = true;
						}
						else if(header.is_property("right") && mask.relate_same_right) {
							if(header.is_type("uint16_t")) {
								std::memcpy(relate_same.m_right.vptr(), reinterpret_cast<uint16_t const*>(input_buffer), std::min(size_t(relate_same.size_used) * sizeof(uint16_t), header.record_size));
								serialize_selection.relate_same_right = true;
							}
							else if(header.is_type("uint8_t")) {
								for(uint32_t i = 0; i < std::min(relate_same.size_used, uint32_t(header.record_size / sizeof(uint8_t))); ++i) {
									relate_same.m_right.vptr()[i].value = uint16_t(*(reinterpret_cast<uint8_t const*>(input_buffer) + i));
								}
								serialize_selection.relate_same_right = true;
							}
							else if(header.is_type("uint32_t")) {
								for(uint32_t i = 0; i < std::min(relate_same.size_used, uint32_t(header.record_size / sizeof(uint32_t))); ++i) {
									relate_same.m_right.vptr()[i].value = uint16_t(*(reinterpret_cast<uint32_t const*>(input_buffer) + i));
								}
								serialize_selection.relate_same_right = true;
							}
						}
						else if(header.is_property("$index_end") && mask.relate_same) {
							if(serialize_selection.relate_same_right == true) {
								for(uint32_t i = 0; i < relate_same.size_used; ++i) {
									auto tmp = relate_same.m_right.vptr()[i];
									relate_same.m_right.vptr()[i] = thingyA_id();
									relate_same_set_right(relate_same_id(relate_same_id::value_base_t(i)), tmp);
								}
							}
						}
					} else
					if(header.is_object("relate_in_array") && mask.relate_in_array) {
						if(header.is_property("$size") && header.record_size == sizeof(uint32_t)) {
							if(*(reinterpret_cast<uint32_t const*>(input_buffer)) >= relate_in_array.size_used) {
								relate_in_array_resize(0);
							}
							relate_in_array_resize(*(reinterpret_cast<uint32_t const*>(input_buffer)));
							serialize_selection.relate_in_array = true;
						}
						else if(header.is_property("right") && mask.relate_in_array_right) {
							if(header.is_type("uint16_t")) {
								std::memcpy(relate_in_array.m_right.vptr(), reinterpret_cast<uint16_t const*>(input_buffer), std::min(size_t(relate_in_array.size_used) * sizeof(uint16_t), header.record_size));
								serialize_selection.relate_in_array_right = true;
							}
							else if(header.is_type("uint8_t")) {
								for(uint32_t i = 0; i < std::min(relate_in_array.size_used, uint32_t(header.record_size / sizeof(uint8_t))); ++i) {
									relate_in_array.m_right.vptr()[i].value = uint16_t(*(reinterpret_cast<uint8_t const*>(input_buffer) + i));
								}
								serialize_selection.relate_in_array_right = true;
							}
							else if(header.is_type("uint32_t")) {
								for(uint32_t i = 0; i < std::min(relate_in_array.size_used, uint32_t(header.record_size / sizeof(uint32_t))); ++i) {
									relate_in_array.m_right.vptr()[i].value = uint16_t(*(reinterpret_cast<uint32_t const*>(input_buffer) + i));
								}
								serialize_selection.relate_in_array_right = true;
							}
						}
						else if(header.is_property("$index_end") && mask.relate_in_array) {
							if(serialize_selection.relate_in_array_right == true) {
								for(uint32_t i = 0; i < relate_in_array.size_used; ++i) {
									auto tmp = relate_in_array.m_right.vptr()[i];
									relate_in_array.m_right.vptr()[i] = thingyB_id();
									relate_in_array_set_right(relate_in_array_id(relate_in_array_id::value_base_t(i)), tmp);
								}
							}
						}
					} else
					if(header.is_object("relate_in_list") && mask.relate_in_list) {
						if(header.is_property("$size") && header.record_size == sizeof(uint32_t)) {
							if(*(reinterpret_cast<uint32_t const*>(input_buffer)) >= relate_in_list.size_used) {
								relate_in_list_resize(0);
							}
							relate_in_list_resize(*(reinterpret_cast<uint32_t const*>(input_buffer)));
							serialize_selection.relate_in_list = true;
						}
						else if(header.is_property("right") && mask.relate_in_list_right) {
							if(header.is_type("uint16_t")) {
								std::memcpy(relate_in_list.m_right.vptr(), reinterpret_cast<uint16_t const*>(input_buffer), std::min(size_t(relate_in_list.size_used) * sizeof(uint16_t), header.record_size));
								serialize_selection.relate_in_list_right = true;
							}
							else if(header.is_type("uint8_t")) {
								for(uint32_t i = 0; i < std::min(relate_in_list.size_used, uint32_t(header.record_size / sizeof(uint8_t))); ++i) {
									relate_in_list.m_right.vptr()[i].value = uint16_t(*(reinterpret_cast<uint8_t const*>(input_buffer) + i));
								}
								serialize_selection.relate_in_list_right = true;
							}
							else if(header.is_type("uint32_t")) {
								for(uint32_t i = 0; i < std::min(relate_in_list.size_used, uint32_t(header.record_size / sizeof(uint32_t))); ++i) {
									relate_in_list.m_right.vptr()[i].value = uint16_t(*(reinterpret_cast<uint32_t const*>(input_buffer) + i));
								}
								serialize_selection.relate_in_list_right = true;
							}
						}
						else if(header.is_property("$index_end") && mask.relate_in_list) {
							if(serialize_selection.relate_in_list_right == true) {
								for(uint32_t i = 0; i < relate_in_list.size_used; ++i) {
									auto tmp = relate_in_list.m_right.vptr()[i];
									relate_in_list.m_right.vptr()[i] = thingyB_id();
									relate_in_list_set_right(relate_in_list_id(relate_in_list_id::value_base_t(i)), tmp);
								}
							}
						}
					}
				}
				input_buffer += header.record_size;
			}
		}
		

	};

	class thingyA_const_fat_id;
	class thingyA_fat_id;
	class thingyB_const_fat_id;
	class thingyB_fat_id;
	class relate_same_const_fat_id;
	class relate_same_fat_id;
	class relate_in_array_const_fat_id;
	class relate_in_array_fat_id;
	class relate_in_list_const_fat_id;
	class relate_in_list_fat_id;
	class thingyA_fat_id {
		public:
		data_container& container;
		thingyA_id id;
		thingyA_fat_id(data_container& c, thingyA_id i) noexcept : container(c), id(i) {}
		thingyA_fat_id(thingyA_fat_id const& o) noexcept : container(o.container), id(o.id) {}
		DCON_RELEASE_INLINE operator thingyA_id() const noexcept { return id; }
		DCON_RELEASE_INLINE thingyA_fat_id& operator=(thingyA_fat_id const& other) noexcept {
			assert(&container == &other.container);
			id = other.id;
			return *this;
		}
		DCON_RELEASE_INLINE thingyA_fat_id& operator=(thingyA_id other) noexcept {
			id = other;
			return *this;
		}
		DCON_RELEASE_INLINE bool operator==(thingyA_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id == other.id;
		}
		DCON_RELEASE_INLINE bool operator==(thingyA_id other) const noexcept {
			return id == other;
		}
		DCON_RELEASE_INLINE bool operator!=(thingyA_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id != other.id;
		}
		DCON_RELEASE_INLINE bool operator!=(thingyA_id other) const noexcept {
			return id != other;
		}
		explicit operator bool() const noexcept { return bool(id); }
		DCON_RELEASE_INLINE bool is_valid() const noexcept {
			return container.thingyA_is_valid(id);
		}
		DCON_RELEASE_INLINE int32_t& get_some_value() const noexcept;
		DCON_RELEASE_INLINE void set_some_value(int32_t v) const noexcept;
		DCON_RELEASE_INLINE relate_same_fat_id get_relate_same_as_left() const noexcept;
		DCON_RELEASE_INLINE void remove_relate_same_as_left() const noexcept;
		DCON_RELEASE_INLINE relate_in_array_fat_id get_relate_in_array_as_left() const noexcept;
		DCON_RELEASE_INLINE void remove_relate_in_array_as_left() const noexcept;
		DCON_RELEASE_INLINE relate_in_array_fat_id get_relate_in_array() const noexcept;
		DCON_RELEASE_INLINE void remove_relate_in_array() const noexcept;
		DCON_RELEASE_INLINE thingyB_fat_id get_right_from_relate_in_array() const noexcept;
		DCON_RELEASE_INLINE relate_in_list_fat_id get_relate_in_list_as_left() const noexcept;
		DCON_RELEASE_INLINE void remove_relate_in_list_as_left() const noexcept;
		DCON_RELEASE_INLINE relate_in_list_fat_id get_relate_in_list() const noexcept;
		DCON_RELEASE_INLINE void remove_relate_in_list() const noexcept;
		DCON_RELEASE_INLINE thingyB_fat_id get_right_from_relate_in_list() const noexcept;
	};
	DCON_RELEASE_INLINE thingyA_fat_id fatten(data_container& c, thingyA_id id) noexcept {
		return thingyA_fat_id(c, id);
	}
	
	class thingyA_const_fat_id {
		public:
		data_container const& container;
		thingyA_id id;
		thingyA_const_fat_id(data_container const& c, thingyA_id i) noexcept : container(c), id(i) {}
		thingyA_const_fat_id(thingyA_const_fat_id const& o) noexcept : container(o.container), id(o.id) {}
		thingyA_const_fat_id(thingyA_fat_id const& o) noexcept : container(o.container), id(o.id) {}
		DCON_RELEASE_INLINE operator thingyA_id() const noexcept { return id; }
		DCON_RELEASE_INLINE thingyA_const_fat_id& operator=(thingyA_const_fat_id const& other) noexcept {
			assert(&container == &other.container);
			id = other.id;
			return *this;
		}
		DCON_RELEASE_INLINE thingyA_const_fat_id& operator=(thingyA_fat_id const& other) noexcept {
			assert(&container == &other.container);
			id = other.id;
			return *this;
		}
		DCON_RELEASE_INLINE thingyA_const_fat_id& operator=(thingyA_id other) noexcept {
			id = other;
			return *this;
		}
		DCON_RELEASE_INLINE bool operator==(thingyA_const_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id == other.id;
		}
		DCON_RELEASE_INLINE bool operator==(thingyA_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id == other.id;
		}
		DCON_RELEASE_INLINE bool operator==(thingyA_id other) const noexcept {
			return id == other;
		}
		DCON_RELEASE_INLINE bool operator!=(thingyA_const_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id != other.id;
		}
		DCON_RELEASE_INLINE bool operator!=(thingyA_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id != other.id;
		}
		DCON_RELEASE_INLINE bool operator!=(thingyA_id other) const noexcept {
			return id != other;
		}
		DCON_RELEASE_INLINE explicit operator bool() const noexcept { return bool(id); }
		DCON_RELEASE_INLINE bool is_valid() const noexcept {
			return container.thingyA_is_valid(id);
		}
		DCON_RELEASE_INLINE int32_t const& get_some_value() const noexcept;
		DCON_RELEASE_INLINE relate_same_const_fat_id get_relate_same_as_left() const noexcept;
		DCON_RELEASE_INLINE relate_in_array_const_fat_id get_relate_in_array_as_left() const noexcept;
		DCON_RELEASE_INLINE relate_in_array_const_fat_id get_relate_in_array() const noexcept;
		DCON_RELEASE_INLINE thingyB_const_fat_id get_right_from_relate_in_array() const noexcept;
		DCON_RELEASE_INLINE relate_in_list_const_fat_id get_relate_in_list_as_left() const noexcept;
		DCON_RELEASE_INLINE relate_in_list_const_fat_id get_relate_in_list() const noexcept;
		DCON_RELEASE_INLINE thingyB_const_fat_id get_right_from_relate_in_list() const noexcept;
	};
	DCON_RELEASE_INLINE bool operator==(thingyA_fat_id const& l, thingyA_const_fat_id const& other) noexcept {
		assert(&l.container == &other.container);
		return l.id == other.id;
	}
	DCON_RELEASE_INLINE bool operator!=(thingyA_fat_id const& l, thingyA_const_fat_id const& other) noexcept {
		assert(&l.container == &other.container);
		return l.id != other.id;
	}
	DCON_RELEASE_INLINE thingyA_const_fat_id fatten(data_container const& c, thingyA_id id) noexcept {
		return thingyA_const_fat_id(c, id);
	}
	
	class thingyB_fat_id {
		public:
		data_container& container;
		thingyB_id id;
		thingyB_fat_id(data_container& c, thingyB_id i) noexcept : container(c), id(i) {}
		thingyB_fat_id(thingyB_fat_id const& o) noexcept : container(o.container), id(o.id) {}
		DCON_RELEASE_INLINE operator thingyB_id() const noexcept { return id; }
		DCON_RELEASE_INLINE thingyB_fat_id& operator=(thingyB_fat_id const& other) noexcept {
			assert(&container == &other.container);
			id = other.id;
			return *this;
		}
		DCON_RELEASE_INLINE thingyB_fat_id& operator=(thingyB_id other) noexcept {
			id = other;
			return *this;
		}
		DCON_RELEASE_INLINE bool operator==(thingyB_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id == other.id;
		}
		DCON_RELEASE_INLINE bool operator==(thingyB_id other) const noexcept {
			return id == other;
		}
		DCON_RELEASE_INLINE bool operator!=(thingyB_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id != other.id;
		}
		DCON_RELEASE_INLINE bool operator!=(thingyB_id other) const noexcept {
			return id != other;
		}
		explicit operator bool() const noexcept { return bool(id); }
		DCON_RELEASE_INLINE bool is_valid() const noexcept {
			return container.thingyB_is_valid(id);
		}
		DCON_RELEASE_INLINE int32_t& get_some_value() const noexcept;
		DCON_RELEASE_INLINE void set_some_value(int32_t v) const noexcept;
		template<typename T>
		DCON_RELEASE_INLINE void for_each_relate_in_array_as_right(T&& func) const;
		DCON_RELEASE_INLINE std::pair<relate_in_array_id const*, relate_in_array_id const*> range_of_relate_in_array_as_right() const;
		DCON_RELEASE_INLINE void remove_all_relate_in_array_as_right() const noexcept;
		template<typename T>
		DCON_RELEASE_INLINE void for_each_relate_in_array(T&& func) const;
		DCON_RELEASE_INLINE std::pair<relate_in_array_id const*, relate_in_array_id const*> range_of_relate_in_array() const;
		DCON_RELEASE_INLINE void remove_all_relate_in_array() const noexcept;
		template<typename T>
		DCON_RELEASE_INLINE void for_each_left_from_relate_in_array(T&& func) const;
		DCON_RELEASE_INLINE bool has_left_from_relate_in_array(thingyA_id target) const;
		template<typename T>
		DCON_RELEASE_INLINE void for_each_relate_in_list_as_right(T&& func) const;
		DCON_RELEASE_INLINE void remove_all_relate_in_list_as_right() const noexcept;
		template<typename T>
		DCON_RELEASE_INLINE void for_each_relate_in_list(T&& func) const;
		DCON_RELEASE_INLINE void remove_all_relate_in_list() const noexcept;
		template<typename T>
		DCON_RELEASE_INLINE void for_each_left_from_relate_in_list(T&& func) const;
		DCON_RELEASE_INLINE bool has_left_from_relate_in_list(thingyA_id target) const;
	};
	DCON_RELEASE_INLINE thingyB_fat_id fatten(data_container& c, thingyB_id id) noexcept {
		return thingyB_fat_id(c, id);
	}
	
	class thingyB_const_fat_id {
		public:
		data_container const& container;
		thingyB_id id;
		thingyB_const_fat_id(data_container const& c, thingyB_id i) noexcept : container(c), id(i) {}
		thingyB_const_fat_id(thingyB_const_fat_id const& o) noexcept : container(o.container), id(o.id) {}
		thingyB_const_fat_id(thingyB_fat_id const& o) noexcept : container(o.container), id(o.id) {}
		DCON_RELEASE_INLINE operator thingyB_id() const noexcept { return id; }
		DCON_RELEASE_INLINE thingyB_const_fat_id& operator=(thingyB_const_fat_id const& other) noexcept {
			assert(&container == &other.container);
			id = other.id;
			return *this;
		}
		DCON_RELEASE_INLINE thingyB_const_fat_id& operator=(thingyB_fat_id const& other) noexcept {
			assert(&container == &other.container);
			id = other.id;
			return *this;
		}
		DCON_RELEASE_INLINE thingyB_const_fat_id& operator=(thingyB_id other) noexcept {
			id = other;
			return *this;
		}
		DCON_RELEASE_INLINE bool operator==(thingyB_const_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id == other.id;
		}
		DCON_RELEASE_INLINE bool operator==(thingyB_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id == other.id;
		}
		DCON_RELEASE_INLINE bool operator==(thingyB_id other) const noexcept {
			return id == other;
		}
		DCON_RELEASE_INLINE bool operator!=(thingyB_const_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id != other.id;
		}
		DCON_RELEASE_INLINE bool operator!=(thingyB_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id != other.id;
		}
		DCON_RELEASE_INLINE bool operator!=(thingyB_id other) const noexcept {
			return id != other;
		}
		DCON_RELEASE_INLINE explicit operator bool() const noexcept { return bool(id); }
		DCON_RELEASE_INLINE bool is_valid() const noexcept {
			return container.thingyB_is_valid(id);
		}
		DCON_RELEASE_INLINE int32_t const& get_some_value() const noexcept;
		template<typename T>
		DCON_RELEASE_INLINE void for_each_relate_in_array_as_right(T&& func) const;
		DCON_RELEASE_INLINE std::pair<relate_in_array_id const*, relate_in_array_id const*> range_of_relate_in_array_as_right() const;
		template<typename T>
		DCON_RELEASE_INLINE void for_each_relate_in_array(T&& func) const;
		DCON_RELEASE_INLINE std::pair<relate_in_array_id const*, relate_in_array_id const*> range_of_relate_in_array() const;
		template<typename T>
		DCON_RELEASE_INLINE void for_each_left_from_relate_in_array(T&& func) const;
		DCON_RELEASE_INLINE bool has_left_from_relate_in_array(thingyA_id target) const;
		template<typename T>
		DCON_RELEASE_INLINE void for_each_relate_in_list_as_right(T&& func) const;
		template<typename T>
		DCON_RELEASE_INLINE void for_each_relate_in_list(T&& func) const;
		template<typename T>
		DCON_RELEASE_INLINE void for_each_left_from_relate_in_list(T&& func) const;
		DCON_RELEASE_INLINE bool has_left_from_relate_in_list(thingyA_id target) const;
	};
	DCON_RELEASE_INLINE bool operator==(thingyB_fat_id const& l, thingyB_const_fat_id const& other) noexcept {
		assert(&l.container == &other.container);
		return l.id == other.id;
	}
	DCON_RELEASE_INLINE bool operator!=(thingyB_fat_id const& l, thingyB_const_fat_id const& other) noexcept {
		assert(&l.container == &other.container);
		return l.id != other.id;
	}
	DCON_RELEASE_INLINE thingyB_const_fat_id fatten(data_container const& c, thingyB_id id) noexcept {
		return thingyB_const_fat_id(c, id);
	}
	
	class relate_same_fat_id {
		public:
		data_container& container;
		relate_same_id id;
		relate_same_fat_id(data_container& c, relate_same_id i) noexcept : container(c), id(i) {}
		relate_same_fat_id(relate_same_fat_id const& o) noexcept : container(o.container), id(o.id) {}
		DCON_RELEASE_INLINE operator relate_same_id() const noexcept { return id; }
		DCON_RELEASE_INLINE relate_same_fat_id& operator=(relate_same_fat_id const& other) noexcept {
			assert(&container == &other.container);
			id = other.id;
			return *this;
		}
		DCON_RELEASE_INLINE relate_same_fat_id& operator=(relate_same_id other) noexcept {
			id = other;
			return *this;
		}
		DCON_RELEASE_INLINE bool operator==(relate_same_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id == other.id;
		}
		DCON_RELEASE_INLINE bool operator==(relate_same_id other) const noexcept {
			return id == other;
		}
		DCON_RELEASE_INLINE bool operator!=(relate_same_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id != other.id;
		}
		DCON_RELEASE_INLINE bool operator!=(relate_same_id other) const noexcept {
			return id != other;
		}
		explicit operator bool() const noexcept { return bool(id); }
		DCON_RELEASE_INLINE bool is_valid() const noexcept {
			return container.relate_same_is_valid(id);
		}
		DCON_RELEASE_INLINE thingyA_fat_id get_left() const noexcept;
		DCON_RELEASE_INLINE void set_left(thingyA_id val) const noexcept;
		DCON_RELEASE_INLINE thingyA_fat_id get_right() const noexcept;
		DCON_RELEASE_INLINE void set_right(thingyA_id val) const noexcept;
	};
	DCON_RELEASE_INLINE relate_same_fat_id fatten(data_container& c, relate_same_id id) noexcept {
		return relate_same_fat_id(c, id);
	}
	
	class relate_same_const_fat_id {
		public:
		data_container const& container;
		relate_same_id id;
		relate_same_const_fat_id(data_container const& c, relate_same_id i) noexcept : container(c), id(i) {}
		relate_same_const_fat_id(relate_same_const_fat_id const& o) noexcept : container(o.container), id(o.id) {}
		relate_same_const_fat_id(relate_same_fat_id const& o) noexcept : container(o.container), id(o.id) {}
		DCON_RELEASE_INLINE operator relate_same_id() const noexcept { return id; }
		DCON_RELEASE_INLINE relate_same_const_fat_id& operator=(relate_same_const_fat_id const& other) noexcept {
			assert(&container == &other.container);
			id = other.id;
			return *this;
		}
		DCON_RELEASE_INLINE relate_same_const_fat_id& operator=(relate_same_fat_id const& other) noexcept {
			assert(&container == &other.container);
			id = other.id;
			return *this;
		}
		DCON_RELEASE_INLINE relate_same_const_fat_id& operator=(relate_same_id other) noexcept {
			id = other;
			return *this;
		}
		DCON_RELEASE_INLINE bool operator==(relate_same_const_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id == other.id;
		}
		DCON_RELEASE_INLINE bool operator==(relate_same_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id == other.id;
		}
		DCON_RELEASE_INLINE bool operator==(relate_same_id other) const noexcept {
			return id == other;
		}
		DCON_RELEASE_INLINE bool operator!=(relate_same_const_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id != other.id;
		}
		DCON_RELEASE_INLINE bool operator!=(relate_same_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id != other.id;
		}
		DCON_RELEASE_INLINE bool operator!=(relate_same_id other) const noexcept {
			return id != other;
		}
		DCON_RELEASE_INLINE explicit operator bool() const noexcept { return bool(id); }
		DCON_RELEASE_INLINE bool is_valid() const noexcept {
			return container.relate_same_is_valid(id);
		}
		DCON_RELEASE_INLINE thingyA_const_fat_id get_left() const noexcept;
		DCON_RELEASE_INLINE thingyA_const_fat_id get_right() const noexcept;
	};
	DCON_RELEASE_INLINE bool operator==(relate_same_fat_id const& l, relate_same_const_fat_id const& other) noexcept {
		assert(&l.container == &other.container);
		return l.id == other.id;
	}
	DCON_RELEASE_INLINE bool operator!=(relate_same_fat_id const& l, relate_same_const_fat_id const& other) noexcept {
		assert(&l.container == &other.container);
		return l.id != other.id;
	}
	DCON_RELEASE_INLINE relate_same_const_fat_id fatten(data_container const& c, relate_same_id id) noexcept {
		return relate_same_const_fat_id(c, id);
	}
	
	class relate_in_array_fat_id {
		public:
		data_container& container;
		relate_in_array_id id;
		relate_in_array_fat_id(data_container& c, relate_in_array_id i) noexcept : container(c), id(i) {}
		relate_in_array_fat_id(relate_in_array_fat_id const& o) noexcept : container(o.container), id(o.id) {}
		DCON_RELEASE_INLINE operator relate_in_array_id() const noexcept { return id; }
		DCON_RELEASE_INLINE relate_in_array_fat_id& operator=(relate_in_array_fat_id const& other) noexcept {
			assert(&container == &other.container);
			id = other.id;
			return *this;
		}
		DCON_RELEASE_INLINE relate_in_array_fat_id& operator=(relate_in_array_id other) noexcept {
			id = other;
			return *this;
		}
		DCON_RELEASE_INLINE bool operator==(relate_in_array_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id == other.id;
		}
		DCON_RELEASE_INLINE bool operator==(relate_in_array_id other) const noexcept {
			return id == other;
		}
		DCON_RELEASE_INLINE bool operator!=(relate_in_array_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id != other.id;
		}
		DCON_RELEASE_INLINE bool operator!=(relate_in_array_id other) const noexcept {
			return id != other;
		}
		explicit operator bool() const noexcept { return bool(id); }
		DCON_RELEASE_INLINE bool is_valid() const noexcept {
			return container.relate_in_array_is_valid(id);
		}
		DCON_RELEASE_INLINE thingyA_fat_id get_left() const noexcept;
		DCON_RELEASE_INLINE void set_left(thingyA_id val) const noexcept;
		DCON_RELEASE_INLINE thingyB_fat_id get_right() const noexcept;
		DCON_RELEASE_INLINE void set_right(thingyB_id val) const noexcept;
	};
	DCON_RELEASE_INLINE relate_in_array_fat_id fatten(data_container& c, relate_in_array_id id) noexcept {
		return relate_in_array_fat_id(c, id);
	}
	
	class relate_in_array_const_fat_id {
		public:
		data_container const& container;
		relate_in_array_id id;
		relate_in_array_const_fat_id(data_container const& c, relate_in_array_id i) noexcept : container(c), id(i) {}
		relate_in_array_const_fat_id(relate_in_array_const_fat_id const& o) noexcept : container(o.container), id(o.id) {}
		relate_in_array_const_fat_id(relate_in_array_fat_id const& o) noexcept : container(o.container), id(o.id) {}
		DCON_RELEASE_INLINE operator relate_in_array_id() const noexcept { return id; }
		DCON_RELEASE_INLINE relate_in_array_const_fat_id& operator=(relate_in_array_const_fat_id const& other) noexcept {
			assert(&container == &other.container);
			id = other.id;
			return *this;
		}
		DCON_RELEASE_INLINE relate_in_array_const_fat_id& operator=(relate_in_array_fat_id const& other) noexcept {
			assert(&container == &other.container);
			id = other.id;
			return *this;
		}
		DCON_RELEASE_INLINE relate_in_array_const_fat_id& operator=(relate_in_array_id other) noexcept {
			id = other;
			return *this;
		}
		DCON_RELEASE_INLINE bool operator==(relate_in_array_const_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id == other.id;
		}
		DCON_RELEASE_INLINE bool operator==(relate_in_array_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id == other.id;
		}
		DCON_RELEASE_INLINE bool operator==(relate_in_array_id other) const noexcept {
			return id == other;
		}
		DCON_RELEASE_INLINE bool operator!=(relate_in_array_const_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id != other.id;
		}
		DCON_RELEASE_INLINE bool operator!=(relate_in_array_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id != other.id;
		}
		DCON_RELEASE_INLINE bool operator!=(relate_in_array_id other) const noexcept {
			return id != other;
		}
		DCON_RELEASE_INLINE explicit operator bool() const noexcept { return bool(id); }
		DCON_RELEASE_INLINE bool is_valid() const noexcept {
			return container.relate_in_array_is_valid(id);
		}
		DCON_RELEASE_INLINE thingyA_const_fat_id get_left() const noexcept;
		DCON_RELEASE_INLINE thingyB_const_fat_id get_right() const noexcept;
	};
	DCON_RELEASE_INLINE bool operator==(relate_in_array_fat_id const& l, relate_in_array_const_fat_id const& other) noexcept {
		assert(&l.container == &other.container);
		return l.id == other.id;
	}
	DCON_RELEASE_INLINE bool operator!=(relate_in_array_fat_id const& l, relate_in_array_const_fat_id const& other) noexcept {
		assert(&l.container == &other.container);
		return l.id != other.id;
	}
	DCON_RELEASE_INLINE relate_in_array_const_fat_id fatten(data_container const& c, relate_in_array_id id) noexcept {
		return relate_in_array_const_fat_id(c, id);
	}
	
	class relate_in_list_fat_id {
		public:
		data_container& container;
		relate_in_list_id id;
		relate_in_list_fat_id(data_container& c, relate_in_list_id i) noexcept : container(c), id(i) {}
		relate_in_list_fat_id(relate_in_list_fat_id const& o) noexcept : container(o.container), id(o.id) {}
		DCON_RELEASE_INLINE operator relate_in_list_id() const noexcept { return id; }
		DCON_RELEASE_INLINE relate_in_list_fat_id& operator=(relate_in_list_fat_id const& other) noexcept {
			assert(&container == &other.container);
			id = other.id;
			return *this;
		}
		DCON_RELEASE_INLINE relate_in_list_fat_id& operator=(relate_in_list_id other) noexcept {
			id = other;
			return *this;
		}
		DCON_RELEASE_INLINE bool operator==(relate_in_list_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id == other.id;
		}
		DCON_RELEASE_INLINE bool operator==(relate_in_list_id other) const noexcept {
			return id == other;
		}
		DCON_RELEASE_INLINE bool operator!=(relate_in_list_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id != other.id;
		}
		DCON_RELEASE_INLINE bool operator!=(relate_in_list_id other) const noexcept {
			return id != other;
		}
		explicit operator bool() const noexcept { return bool(id); }
		DCON_RELEASE_INLINE bool is_valid() const noexcept {
			return container.relate_in_list_is_valid(id);
		}
		DCON_RELEASE_INLINE thingyA_fat_id get_left() const noexcept;
		DCON_RELEASE_INLINE void set_left(thingyA_id val) const noexcept;
		DCON_RELEASE_INLINE thingyB_fat_id get_right() const noexcept;
		DCON_RELEASE_INLINE void set_right(thingyB_id val) const noexcept;
	};
	DCON_RELEASE_INLINE relate_in_list_fat_id fatten(data_container& c, relate_in_list_id id) noexcept {
		return relate_in_list_fat_id(c, id);
	}
	
	class relate_in_list_const_fat_id {
		public:
		data_container const& container;
		relate_in_list_id id;
		relate_in_list_const_fat_id(data_container const& c, relate_in_list_id i) noexcept : container(c), id(i) {}
		relate_in_list_const_fat_id(relate_in_list_const_fat_id const& o) noexcept : container(o.container), id(o.id) {}
		relate_in_list_const_fat_id(relate_in_list_fat_id const& o) noexcept : container(o.container), id(o.id) {}
		DCON_RELEASE_INLINE operator relate_in_list_id() const noexcept { return id; }
		DCON_RELEASE_INLINE relate_in_list_const_fat_id& operator=(relate_in_list_const_fat_id const& other) noexcept {
			assert(&container == &other.container);
			id = other.id;
			return *this;
		}
		DCON_RELEASE_INLINE relate_in_list_const_fat_id& operator=(relate_in_list_fat_id const& other) noexcept {
			assert(&container == &other.container);
			id = other.id;
			return *this;
		}
		DCON_RELEASE_INLINE relate_in_list_const_fat_id& operator=(relate_in_list_id other) noexcept {
			id = other;
			return *this;
		}
		DCON_RELEASE_INLINE bool operator==(relate_in_list_const_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id == other.id;
		}
		DCON_RELEASE_INLINE bool operator==(relate_in_list_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id == other.id;
		}
		DCON_RELEASE_INLINE bool operator==(relate_in_list_id other) const noexcept {
			return id == other;
		}
		DCON_RELEASE_INLINE bool operator!=(relate_in_list_const_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id != other.id;
		}
		DCON_RELEASE_INLINE bool operator!=(relate_in_list_fat_id const& other) const noexcept {
			assert(&container == &other.container);
			return id != other.id;
		}
		DCON_RELEASE_INLINE bool operator!=(relate_in_list_id other) const noexcept {
			return id != other;
		}
		DCON_RELEASE_INLINE explicit operator bool() const noexcept { return bool(id); }
		DCON_RELEASE_INLINE bool is_valid() const noexcept {
			return container.relate_in_list_is_valid(id);
		}
		DCON_RELEASE_INLINE thingyA_const_fat_id get_left() const noexcept;
		DCON_RELEASE_INLINE thingyB_const_fat_id get_right() const noexcept;
	};
	DCON_RELEASE_INLINE bool operator==(relate_in_list_fat_id const& l, relate_in_list_const_fat_id const& other) noexcept {
		assert(&l.container == &other.container);
		return l.id == other.id;
	}
	DCON_RELEASE_INLINE bool operator!=(relate_in_list_fat_id const& l, relate_in_list_const_fat_id const& other) noexcept {
		assert(&l.container == &other.container);
		return l.id != other.id;
	}
	DCON_RELEASE_INLINE relate_in_list_const_fat_id fatten(data_container const& c, relate_in_list_id id) noexcept {
		return relate_in_list_const_fat_id(c, id);
	}
	
	DCON_RELEASE_INLINE int32_t& thingyA_fat_id::get_some_value() const noexcept { return container.thingyA_get_some_value(id); }
	DCON_RELEASE_INLINE void thingyA_fat_id::set_some_value(int32_t v) const noexcept { container.thingyA_set_some_value(id, v); }
	DCON_RELEASE_INLINE relate_same_fat_id thingyA_fat_id::get_relate_same_as_left() const noexcept {
		return relate_same_fat_id(container, container.thingyA_get_relate_same_as_left(id));
	}
	DCON_RELEASE_INLINE void thingyA_fat_id::remove_relate_same_as_left() const noexcept {
		container.thingyA_remove_relate_same_as_left(id);
	}
	DCON_RELEASE_INLINE relate_in_array_fat_id thingyA_fat_id::get_relate_in_array_as_left() const noexcept {
		return relate_in_array_fat_id(container, container.thingyA_get_relate_in_array_as_left(id));
	}
	DCON_RELEASE_INLINE void thingyA_fat_id::remove_relate_in_array_as_left() const noexcept {
		container.thingyA_remove_relate_in_array_as_left(id);
	}
	DCON_RELEASE_INLINE relate_in_array_fat_id thingyA_fat_id::get_relate_in_array() const noexcept {
		return relate_in_array_fat_id(container, container.thingyA_get_relate_in_array(id));
	}
	DCON_RELEASE_INLINE void thingyA_fat_id::remove_relate_in_array() const noexcept {
		container.thingyA_remove_relate_in_array(id);
	}
	DCON_RELEASE_INLINE thingyB_fat_id thingyA_fat_id::get_right_from_relate_in_array() const noexcept {
		return thingyB_fat_id(container, container.thingyA_get_right_from_relate_in_array(id));
	}
	DCON_RELEASE_INLINE relate_in_list_fat_id thingyA_fat_id::get_relate_in_list_as_left() const noexcept {
		return relate_in_list_fat_id(container, container.thingyA_get_relate_in_list_as_left(id));
	}
	DCON_RELEASE_INLINE void thingyA_fat_id::remove_relate_in_list_as_left() const noexcept {
		container.thingyA_remove_relate_in_list_as_left(id);
	}
	DCON_RELEASE_INLINE relate_in_list_fat_id thingyA_fat_id::get_relate_in_list() const noexcept {
		return relate_in_list_fat_id(container, container.thingyA_get_relate_in_list(id));
	}
	DCON_RELEASE_INLINE void thingyA_fat_id::remove_relate_in_list() const noexcept {
		container.thingyA_remove_relate_in_list(id);
	}
	DCON_RELEASE_INLINE thingyB_fat_id thingyA_fat_id::get_right_from_relate_in_list() const noexcept {
		return thingyB_fat_id(container, container.thingyA_get_right_from_relate_in_list(id));
	}
	
	DCON_RELEASE_INLINE int32_t const& thingyA_const_fat_id::get_some_value() const noexcept { return container.thingyA_get_some_value(id); }
	DCON_RELEASE_INLINE relate_same_const_fat_id thingyA_const_fat_id::get_relate_same_as_left() const noexcept {
		return relate_same_const_fat_id(container, container.thingyA_get_relate_same_as_left(id));
	}
	DCON_RELEASE_INLINE relate_in_array_const_fat_id thingyA_const_fat_id::get_relate_in_array_as_left() const noexcept {
		return relate_in_array_const_fat_id(container, container.thingyA_get_relate_in_array_as_left(id));
	}
	DCON_RELEASE_INLINE relate_in_array_const_fat_id thingyA_const_fat_id::get_relate_in_array() const noexcept {
		return relate_in_array_const_fat_id(container, container.thingyA_get_relate_in_array(id));
	}
	DCON_RELEASE_INLINE thingyB_const_fat_id thingyA_const_fat_id::get_right_from_relate_in_array() const noexcept {
		return thingyB_const_fat_id(container, container.thingyA_get_right_from_relate_in_array(id));
	}
	DCON_RELEASE_INLINE relate_in_list_const_fat_id thingyA_const_fat_id::get_relate_in_list_as_left() const noexcept {
		return relate_in_list_const_fat_id(container, container.thingyA_get_relate_in_list_as_left(id));
	}
	DCON_RELEASE_INLINE relate_in_list_const_fat_id thingyA_const_fat_id::get_relate_in_list() const noexcept {
		return relate_in_list_const_fat_id(container, container.thingyA_get_relate_in_list(id));
	}
	DCON_RELEASE_INLINE thingyB_const_fat_id thingyA_const_fat_id::get_right_from_relate_in_list() const noexcept {
		return thingyB_const_fat_id(container, container.thingyA_get_right_from_relate_in_list(id));
	}
	
	DCON_RELEASE_INLINE int32_t& thingyB_fat_id::get_some_value() const noexcept { return container.thingyB_get_some_value(id); }
	DCON_RELEASE_INLINE void thingyB_fat_id::set_some_value(int32_t v) const noexcept { container.thingyB_set_some_value(id, v); }
	template<typename T>
	DCON_RELEASE_INLINE void thingyB_fat_id::for_each_relate_in_array_as_right(T&& func) const {
		container.thingyB_for_each_relate_in_array_as_right(id, [&, t = this](relate_in_array_id i){func(fatten(t->container, i));});
	}
	DCON_RELEASE_INLINE std::pair<relate_in_array_id const*, relate_in_array_id const*> thingyB_fat_id::range_of_relate_in_array_as_right() const {
		return container.thingyB_range_of_relate_in_array_as_right(id);
	}
	DCON_RELEASE_INLINE void thingyB_fat_id::remove_all_relate_in_array_as_right() const noexcept {
		container.thingyB_remove_all_relate_in_array_as_right(id);
	}
	template<typename T>
	DCON_RELEASE_INLINE void thingyB_fat_id::for_each_relate_in_array(T&& func) const {
		container.thingyB_for_each_relate_in_array(id, [&, t = this](relate_in_array_id i){func(fatten(t->container, i));});
	}
	DCON_RELEASE_INLINE std::pair<relate_in_array_id const*, relate_in_array_id const*> thingyB_fat_id::range_of_relate_in_array() const {
		return container.thingyB_range_of_relate_in_array(id);
	}
	DCON_RELEASE_INLINE void thingyB_fat_id::remove_all_relate_in_array() const noexcept {
		container.thingyB_remove_all_relate_in_array(id);
	}
	template<typename T>
	DCON_RELEASE_INLINE void thingyB_fat_id::for_each_left_from_relate_in_array(T&& func) const {
		container.thingyB_for_each_left_from_relate_in_array(id, [&, t = this](thingyA_id i){func(fatten(t->container, i));});
	}
	DCON_RELEASE_INLINE bool thingyB_fat_id::has_left_from_relate_in_array(thingyA_id target) const {
		return container.thingyB_has_left_from_relate_in_array(id, target);
	}
	template<typename T>
	DCON_RELEASE_INLINE void thingyB_fat_id::for_each_relate_in_list_as_right(T&& func) const {
		container.thingyB_for_each_relate_in_list_as_right(id, [&, t = this](relate_in_list_id i){func(fatten(t->container, i));});
	}
	DCON_RELEASE_INLINE void thingyB_fat_id::remove_all_relate_in_list_as_right() const noexcept {
		container.thingyB_remove_all_relate_in_list_as_right(id);
	}
	template<typename T>
	DCON_RELEASE_INLINE void thingyB_fat_id::for_each_relate_in_list(T&& func) const {
		container.thingyB_for_each_relate_in_list(id, [&, t = this](relate_in_list_id i){func(fatten(t->container, i));});
	}
	DCON_RELEASE_INLINE void thingyB_fat_id::remove_all_relate_in_list() const noexcept {
		container.thingyB_remove_all_relate_in_list(id);
	}
	template<typename T>
	DCON_RELEASE_INLINE void thingyB_fat_id::for_each_left_from_relate_in_list(T&& func) const {
		container.thingyB_for_each_left_from_relate_in_list(id, [&, t = this](thingyA_id i){func(fatten(t->container, i));});
	}
	DCON_RELEASE_INLINE bool thingyB_fat_id::has_left_from_relate_in_list(thingyA_id target) const {
		return container.thingyB_has_left_from_relate_in_list(id, target);
	}
	
	DCON_RELEASE_INLINE int32_t const& thingyB_const_fat_id::get_some_value() const noexcept { return container.thingyB_get_some_value(id); }
	template<typename T>
	DCON_RELEASE_INLINE void thingyB_const_fat_id::for_each_relate_in_array_as_right(T&& func) const {
		container.thingyB_for_each_relate_in_array_as_right(id, [&, t = this](relate_in_array_id i){func(fatten(t->container, i));});
	}
	DCON_RELEASE_INLINE std::pair<relate_in_array_id const*, relate_in_array_id const*> thingyB_const_fat_id::range_of_relate_in_array_as_right() const {
		return container.thingyB_range_of_relate_in_array_as_right(id);
	}
	template<typename T>
	DCON_RELEASE_INLINE void thingyB_const_fat_id::for_each_relate_in_array(T&& func) const {
		container.thingyB_for_each_relate_in_array(id, [&, t = this](relate_in_array_id i){func(fatten(t->container, i));});
	}
	DCON_RELEASE_INLINE std::pair<relate_in_array_id const*, relate_in_array_id const*> thingyB_const_fat_id::range_of_relate_in_array() const {
		return container.thingyB_range_of_relate_in_array(id);
	}
	template<typename T>
	DCON_RELEASE_INLINE void thingyB_const_fat_id::for_each_left_from_relate_in_array(T&& func) const {
		container.thingyB_for_each_left_from_relate_in_array(id, [&, t = this](thingyA_id i){func(fatten(t->container, i));});
	}
	DCON_RELEASE_INLINE bool thingyB_const_fat_id::has_left_from_relate_in_array(thingyA_id target) const {
		return container.thingyB_has_left_from_relate_in_array(id, target);
	}
	template<typename T>
	DCON_RELEASE_INLINE void thingyB_const_fat_id::for_each_relate_in_list_as_right(T&& func) const {
		container.thingyB_for_each_relate_in_list_as_right(id, [&, t = this](relate_in_list_id i){func(fatten(t->container, i));});
	}
	template<typename T>
	DCON_RELEASE_INLINE void thingyB_const_fat_id::for_each_relate_in_list(T&& func) const {
		container.thingyB_for_each_relate_in_list(id, [&, t = this](relate_in_list_id i){func(fatten(t->container, i));});
	}
	template<typename T>
	DCON_RELEASE_INLINE void thingyB_const_fat_id::for_each_left_from_relate_in_list(T&& func) const {
		container.thingyB_for_each_left_from_relate_in_list(id, [&, t = this](thingyA_id i){func(fatten(t->container, i));});
	}
	DCON_RELEASE_INLINE bool thingyB_const_fat_id::has_left_from_relate_in_list(thingyA_id target) const {
		return container.thingyB_has_left_from_relate_in_list(id, target);
	}
	
	DCON_RELEASE_INLINE thingyA_fat_id relate_same_fat_id::get_left() const noexcept {
		return thingyA_fat_id(container, container.relate_same_get_left(id));
	}
	DCON_RELEASE_INLINE void relate_same_fat_id::set_left(thingyA_id val) const noexcept {
		container.relate_same_set_left(id, val);
	}
	DCON_RELEASE_INLINE thingyA_fat_id relate_same_fat_id::get_right() const noexcept {
		return thingyA_fat_id(container, container.relate_same_get_right(id));
	}
	DCON_RELEASE_INLINE void relate_same_fat_id::set_right(thingyA_id val) const noexcept {
		container.relate_same_set_right(id, val);
	}
	
	DCON_RELEASE_INLINE thingyA_const_fat_id relate_same_const_fat_id::get_left() const noexcept {
		return thingyA_const_fat_id(container, container.relate_same_get_left(id));
	}
	DCON_RELEASE_INLINE thingyA_const_fat_id relate_same_const_fat_id::get_right() const noexcept {
		return thingyA_const_fat_id(container, container.relate_same_get_right(id));
	}
	
	DCON_RELEASE_INLINE thingyA_fat_id relate_in_array_fat_id::get_left() const noexcept {
		return thingyA_fat_id(container, container.relate_in_array_get_left(id));
	}
	DCON_RELEASE_INLINE void relate_in_array_fat_id::set_left(thingyA_id val) const noexcept {
		container.relate_in_array_set_left(id, val);
	}
	DCON_RELEASE_INLINE thingyB_fat_id relate_in_array_fat_id::get_right() const noexcept {
		return thingyB_fat_id(container, container.relate_in_array_get_right(id));
	}
	DCON_RELEASE_INLINE void relate_in_array_fat_id::set_right(thingyB_id val) const noexcept {
		container.relate_in_array_set_right(id, val);
	}
	
	DCON_RELEASE_INLINE thingyA_const_fat_id relate_in_array_const_fat_id::get_left() const noexcept {
		return thingyA_const_fat_id(container, container.relate_in_array_get_left(id));
	}
	DCON_RELEASE_INLINE thingyB_const_fat_id relate_in_array_const_fat_id::get_right() const noexcept {
		return thingyB_const_fat_id(container, container.relate_in_array_get_right(id));
	}
	
	DCON_RELEASE_INLINE thingyA_fat_id relate_in_list_fat_id::get_left() const noexcept {
		return thingyA_fat_id(container, container.relate_in_list_get_left(id));
	}
	DCON_RELEASE_INLINE void relate_in_list_fat_id::set_left(thingyA_id val) const noexcept {
		container.relate_in_list_set_left(id, val);
	}
	DCON_RELEASE_INLINE thingyB_fat_id relate_in_list_fat_id::get_right() const noexcept {
		return thingyB_fat_id(container, container.relate_in_list_get_right(id));
	}
	DCON_RELEASE_INLINE void relate_in_list_fat_id::set_right(thingyB_id val) const noexcept {
		container.relate_in_list_set_right(id, val);
	}
	
	DCON_RELEASE_INLINE thingyA_const_fat_id relate_in_list_const_fat_id::get_left() const noexcept {
		return thingyA_const_fat_id(container, container.relate_in_list_get_left(id));
	}
	DCON_RELEASE_INLINE thingyB_const_fat_id relate_in_list_const_fat_id::get_right() const noexcept {
		return thingyB_const_fat_id(container, container.relate_in_list_get_right(id));
	}
	
}

#undef DCON_RELEASE_INLINE
#pragma warning( pop )
