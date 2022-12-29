package com.hugh.tripist.dao;

import java.util.List;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import com.hugh.tripist.vo.TripistVo;

@Mapper
public interface ITripistDao {
	
	public List<TripistVo> confirmSignUp(@Param("tripistVo") TripistVo tripistVo);

	public int addUser(@Param("tripistVo") TripistVo tripistVo);

	public List<TripistVo> confirmSignIn(@Param("tripistVo") TripistVo tripistVo);

	public List<TripistVo> getMarkerList(@Param("tripistVo") Object object);

}
