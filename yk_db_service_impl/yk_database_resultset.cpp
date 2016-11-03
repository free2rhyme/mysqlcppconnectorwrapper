/*
 * yk_database_resultset.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */

#include "yk_database_resultset.h"


YKDatabaseResultset::YKDatabaseResultset(YKCppResultSetShpType& native_result) noexcept(true):
	m_current_row(1), m_cpp_resultset_shp(native_result){
}

YKDatabaseResultset::~YKDatabaseResultset() noexcept(true){

}

YKErrorCode YKDatabaseResultset::find_column_index(const YKString& column_label, uint32_t& index) const noexcept(true){
	try{
		index = m_cpp_resultset_shp->findColumn(column_label);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

//YKErrorCode YKDatabaseResultset::get_current_row_boolean(bool& value) const noexcept(true){
//	try{
//		value = m_cpp_resultset_shp->getBoolean(column_index);
//	}catch(YKInvalidArgumentException& e){
//		YKLogError(e.what());
//		return YK_E_INVALID_PARAMETER;
//	} catch(...){
//		YKLogError("unexpected exception");
//		return YK_E_GENERAL_ERROR;
//	}
//	return YK_E_SUCCESSFUL;
//}
//YKErrorCode YKDatabaseResultset::get_current_row_double(long double& value) const noexcept(true);;
//YKErrorCode YKDatabaseResultset::get_current_row_int32(int32_t& value) const noexcept(true);
//YKErrorCode YKDatabaseResultset::get_current_row_uint32(uint32_t& value) const noexcept(true);
//YKErrorCode YKDatabaseResultset::get_current_row_int64(int64_t& value) const noexcept(true);
//YKErrorCode YKDatabaseResultset::get_current_row_uint64(uint64_t& value) const noexcept(true);
//YKErrorCode YKDatabaseResultset::get_current_row_string(YKString& value) const noexcept(true);

YKErrorCode YKDatabaseResultset::get_boolean(uint32_t column_index, bool& value) const noexcept(true){
	try{
		value = m_cpp_resultset_shp->getBoolean(column_index);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}
YKErrorCode YKDatabaseResultset::get_boolean(const YKString& column_label, bool& value) const noexcept(true){
	try{
		value = m_cpp_resultset_shp->getBoolean(column_label);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseResultset::get_double(const uint32_t column_index, long double& value) const noexcept(true){
	try{
		value = m_cpp_resultset_shp->getDouble(column_index);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseResultset::get_double(const YKString& column_label, long double& value) const noexcept(true){
	try{
		value = m_cpp_resultset_shp->getDouble(column_label);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseResultset::get_int32(const uint32_t column_index, int32_t& value) const noexcept(true){
	try{
		value = m_cpp_resultset_shp->getInt(column_index);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseResultset::get_int32(const YKString& column_label, int32_t& value) const noexcept(true){
	try{
		value = m_cpp_resultset_shp->getInt(column_label);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseResultset::get_uint32(const uint32_t column_index, uint32_t& value) const noexcept(true){
	try{
		value = m_cpp_resultset_shp->getUInt(column_index);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseResultset::get_uint32(const YKString& column_label, uint32_t& value) const noexcept(true){
	try{
		value = m_cpp_resultset_shp->getUInt(column_label);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}
YKErrorCode YKDatabaseResultset::get_int64(const uint32_t column_index, int64_t& value) const noexcept(true){
	try{
		value = m_cpp_resultset_shp->getInt64(column_index);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseResultset::get_int64(const YKString& column_label, int64_t& value) const noexcept(true){
	try{
		value = m_cpp_resultset_shp->getInt64(column_label);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}
YKErrorCode YKDatabaseResultset::get_uint64(const uint32_t column_index, uint64_t& value) const noexcept(true){
	try{
		value = m_cpp_resultset_shp->getUInt64(column_index);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}
YKErrorCode YKDatabaseResultset::get_uint64(const YKString& column_label, uint64_t& value) const noexcept(true){
	try{
		value = m_cpp_resultset_shp->getUInt64(column_label);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseResultset::get_string(const uint32_t column_index, YKString& value) const noexcept(true){
	try{
		value = m_cpp_resultset_shp->getString(column_index);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseResultset::get_string(const YKString& column_label, YKString& value) const noexcept(true){
	try{
		value = m_cpp_resultset_shp->getString(column_label);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseResultset::get_row_position(size_t& value) const noexcept(true){
	try{
		value = m_cpp_resultset_shp->getRow();
		m_current_row = value;
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_SQLEXECUTE_ERROR;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseResultset::rows_count(size_t& value) const noexcept(true){
	try{
		value = m_cpp_resultset_shp->rowsCount();
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_SQLEXECUTE_ERROR;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

bool YKDatabaseResultset::is_closed() const noexcept(true){
	return m_cpp_resultset_shp->isClosed();
}

bool YKDatabaseResultset::is_first_row() const noexcept(true){
	bool result = false;
	try{
		result = m_cpp_resultset_shp->isFirst();
	}catch(YKSQLException& e){
		YKLogError(e.what());
		return false;
	} catch(...){
		YKLogError("unexpected exception");
		return false;
	}
	return result;
}

bool YKDatabaseResultset::is_last_row() const noexcept(true){
	bool result = false;
	try{
		result = m_cpp_resultset_shp->isLast();
	}catch(YKSQLException& e){
		YKLogError(e.what());
		return false;
	} catch(...){
		YKLogError("unexpected exception");
		return false;
	}
	return result;
}

bool YKDatabaseResultset::is_row_null(const uint32_t column_index) const noexcept(true){
	bool result = false;
	try{
		result = m_cpp_resultset_shp->isNull(column_index);
	}catch(YKSQLException& e){
		YKLogError(e.what());
		return false;
	} catch(...){
		YKLogError("unexpected exception");
		return false;
	}
	return result;
}

bool YKDatabaseResultset::is_row_null(const YKString& column_label) const noexcept(true){
	bool result = false;
	try{
		result = m_cpp_resultset_shp->isNull(column_label);
	}catch(YKSQLException& e){
		YKLogError(e.what());
		return false;
	} catch(...){
		YKLogError("unexpected exception");
		return false;
	}
	return result;
}

YKErrorCode YKDatabaseResultset::first()noexcept(true){
	bool result = false;
	try{
		result = m_cpp_resultset_shp->first();
	}catch(YKSQLException& e){
		YKLogError(e.what());
		return YK_E_SQLEXECUTE_ERROR;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return result?YK_E_SUCCESSFUL:YK_E_GENERAL_ERROR;
}

YKErrorCode YKDatabaseResultset::next()noexcept(true){
	bool result = false;
	try{
		result = m_cpp_resultset_shp->next();
	}catch(YKSQLException& e){
		YKLogError(e.what());
		return YK_E_SQLEXECUTE_ERROR;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return result?YK_E_SUCCESSFUL:YK_E_GENERAL_ERROR;
}

YKErrorCode YKDatabaseResultset::previous()noexcept(true){
	bool result = false;
	try{
		result = m_cpp_resultset_shp->next();
	}catch(YKSQLException& e){
		YKLogError(e.what());
		return YK_E_SQLEXECUTE_ERROR;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return result?YK_E_SUCCESSFUL:YK_E_GENERAL_ERROR;
}

YKErrorCode YKDatabaseResultset::close()noexcept(true){
	try{
		m_cpp_resultset_shp->close();
		m_cpp_resultset_shp.reset();
	}catch(YKSQLException& e){
		YKLogError(e.what());
		return YK_E_SQLEXECUTE_ERROR;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}
