package com.hugh.tripist.dao;

import java.util.List;
import java.util.Map;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import com.hugh.tripist.vo.TripistVo;

@Mapper
public interface ITripistDao {
	
	public TripistVo confirmSignUp(@Param("tripistVo") TripistVo tripistVo);

	public int addUser(@Param("tripistVo") TripistVo tripistVo);

	public TripistVo confirmSignIn(@Param("tripistVo") TripistVo tripistVo);

	public List<TripistVo> getMarkerList(@Param("tripistVo") TripistVo tripistVo);

    public TripistVo confirmPwToModify(@Param("tripistVo") TripistVo tripistVo);

	public int modifyMyInfo(@Param("map") Map<String, Object> map);

	public TripistVo getTripistVoForSession(@Param("u_no") int u_no);

    public TripistVo confirmPwToDelete(@Param("tripistVo") TripistVo tripistVo);

	public int deleteAccount(@Param("u_no") int u_no);

    public int insertMarkerInfo(@Param("map") Map<String, Object> map);

	public TripistVo getMarkerInfo(@Param("tripistVo") TripistVo tripistVo);

	public int modifyMarkerInfo(@Param("map") Map<String, Object> map);

    public int deleteMarkerInfo(@Param("tripistVo") TripistVo tripistVo);

}
