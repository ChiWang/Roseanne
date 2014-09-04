/*
 *  $Id: DmpDataBuffer.cc, 2014-07-24 15:11:16 DAMPE $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 20/07/2014
*/

#include <boost/algorithm/string.hpp>
#include "DmpDataBuffer.h"

//-------------------------------------------------------------------
DmpDataBuffer::DmpDataBuffer(){
}

//-------------------------------------------------------------------
DmpDataBuffer::~DmpDataBuffer(){
  DmpLogInfo<<"[DmpDataBuffer::~DmpDataBuffer] +--Deleting input data..."<<DmpLogEndl;
  for(DmpDataBufFolderMap::iterator aFolder=fInputDataBufPool.begin();aFolder!=fInputDataBufPool.end();++aFolder){
    DmpDataBufTreeMap aTreeMap = aFolder->second;
    DmpLogInfo<<"[DmpDataBuffer::~DmpDataBuffer] |  +--"<<aFolder->first<<std::endl;
    for(DmpDataBufTreeMap::iterator aTree=aTreeMap.begin();aTree!=aTreeMap.end();++aTree){
      DmpDataBufBranchMap aBranchMap = aTree->second;
    DmpLogInfo<<"[DmpDataBuffer::~DmpDataBuffer] |  |  +--"<<aTree->first<<std::endl;
      for(DmpDataBufBranchMap::iterator it=aBranchMap.begin();it!=aBranchMap.end();++it){
    DmpLogInfo<<"[DmpDataBuffer::~DmpDataBuffer] |  |  |  +--"<<it->first<<std::endl;
        delete it->second;
      }
    }
  }
  DmpLogInfo<<"[DmpDataBuffer::~DmpDataBuffer] +--Done"<<DmpLogEndl;
    //-------------------------------------------------------------------
  DmpLogInfo<<"[DmpDataBuffer::~DmpDataBuffer] +--Deleting output data..."<<DmpLogEndl;
  for(DmpDataBufFolderMap::iterator aFolder=fDataBufPool.begin();aFolder!=fDataBufPool.end();++aFolder){
    DmpDataBufTreeMap aTreeMap = aFolder->second;
    DmpLogInfo<<"[DmpDataBuffer::~DmpDataBuffer] |  +--"<<aFolder->first<<std::endl;
    for(DmpDataBufTreeMap::iterator aTree=aTreeMap.begin();aTree!=aTreeMap.end();++aTree){
      DmpDataBufBranchMap aBranchMap = aTree->second;
    DmpLogInfo<<"[DmpDataBuffer::~DmpDataBuffer] |  |  +--"<<aTree->first<<std::endl;
      for(DmpDataBufBranchMap::iterator it=aBranchMap.begin();it!=aBranchMap.end();++it){
    DmpLogInfo<<"[DmpDataBuffer::~DmpDataBuffer] |  |  |  +--"<<it->first<<std::endl;
        delete it->second;
      }
    }
  }
  DmpLogInfo<<"[DmpDataBuffer::~DmpDataBuffer] +--Done"<<DmpLogEndl;
}

//-------------------------------------------------------------------
bool DmpDataBuffer::PathCheck(const std::string &checkMe,std::string &folderName,std::string &treeName,std::string &branchName){
  std::vector<std::string> temp;
  boost::split(temp,checkMe,boost::is_any_of("/"));
  if(3 != temp.size()){
    DmpLogError<<"[DmpDataBuffer::PathCheck] wrong path: "<<checkMe<<DmpLogEndl;
    return false;
  }else{
    folderName = temp[0];
    treeName = temp[1];
    branchName = temp[2];
  }
  return true;
}

//-------------------------------------------------------------------
DmpDataBuffer *gDataBuffer = DmpDataBuffer::GetInstance();


