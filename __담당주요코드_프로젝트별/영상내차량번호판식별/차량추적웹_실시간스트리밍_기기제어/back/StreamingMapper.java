package com.group1.licensePlateTrace.userMapper;

import java.util.List;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import com.group1.licensePlateTrace.vo.StreamingVo;

@Mapper
public interface StreamingMapper {

	@Select("SELECT * FROM tbl_camera")
	public List<StreamingVo> getCameraList();

	@Update("UPDATE tbl_camera SET c_status = #{streamingVo.c_status} WHERE c_no = #{streamingVo.c_no}")
	public int setCameraStatus(@Param("streamingVo") StreamingVo streamingVo);

	@Select("SELECT c_id, c_pw FROM tbl_camera WHERE c_no = #{streamingVo.c_no}")
	public StreamingVo getIdPw(@Param("streamingVo") StreamingVo streamingVo);

}
