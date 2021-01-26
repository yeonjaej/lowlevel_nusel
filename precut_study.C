#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TPad.h"
#include "TString.h"
// TC tree; filled at every event.
/*
 cluster_id      = (vector<int>*)0x7ffaf314c1d0
 parent_cluster_id = (vector<int>*)0x7ffaf312e660
 time_slice      = (vector<int>*)0x7ffaf31485b0
 q               = (vector<double>*)0x7ffaf31469f0
 uq              = (vector<double>*)0x7ffaf314b0f0
 vq              = (vector<double>*)0x7ffaf3149f30
 wq              = (vector<double>*)0x7ffaf314d500
 udq             = (vector<double>*)0x7ffaf314ed80
 vdq             = (vector<double>*)0x7ffaf314f100
 wdq             = (vector<double>*)0x7ffaf314f480
 nwire_u         = (vector<int>*)0x7ffaf314f800
 nwire_v         = (vector<int>*)0x7ffaf2e8ce50
 nwire_w         = (vector<int>*)0x7ffaf2e722a0
 flag_u          = (vector<int>*)0x7ffaf2e77ba0
 flag_v          = (vector<int>*)0x7ffaf2e8f190
 flag_w          = (vector<int>*)0x7ffaf2e74130
 wire_index_u    = (vector<vector<int> >*)0x7ffaf2e6f9c0
 wire_index_v    = (vector<vector<int> >*)0x7ffaf571b9f0
 wire_index_w    = (vector<vector<int> >*)0x7ffaf57ad800
 wire_charge_u   = (vector<vector<double> >*)0x7ffaf3147480
 wire_charge_v   = (vector<vector<double> >*)0x7ffaf5d12360
 wire_charge_w   = (vector<vector<double> >*)0x7ffaf5d56280
 wire_charge_err_u = (vector<vector<double> >*)0x7ffaf620b980
 wire_charge_err_v = (vector<vector<double> >*)0x7ffaf654c2e0
 wire_charge_err_w = (vector<vector<double> >*)0x7ffaf5f536a0
 */
  TFile *f_ext = new TFile("nuselDATA_event_match.root");
  TFile *f_nnbar = new TFile("nuselOVERLAY_event_match.root");

  TTree *tree_ext_TC = (TTree*)f_ext->Get("TC");
  TTree *tree_nnbar_TC = (TTree*)f_nnbar->Get("TC");

  TTree *tree_ext_match = (TTree*)f_ext->Get("T_match");
  TTree *tree_ext_flash = (TTree*)f_ext->Get("T_flash");

  TTree *tree_nnbar_match = (TTree*)f_nnbar->Get("T_match");
  TTree *tree_nnbar_flash = (TTree*)f_nnbar->Get("T_flash");

  TTree *tree_nnbar_eval = (TTree*)f_nnbar->Get("T_eval");

  std::vector<int> *cluster_id_v=NULL;
  std::vector<int> *parent_cluster_id_v=NULL;
  std::vector<int> *time_slice_v=NULL;
  std::vector<double> *q_v=NULL;
  std::vector<double> *uq_v=NULL;
  std::vector<double> *vq_v=NULL;
  std::vector<double> *wq_v=NULL;
  std::vector<double> *udq_v=NULL;
  std::vector<double> *vdq_v=NULL;
  std::vector<double> *wdq_v=NULL;
  std::vector<int> *nwire_u_v=NULL;
  std::vector<int> *nwire_v_v=NULL;
  std::vector<int> *nwire_w_v=NULL;
  std::vector<int> *flag_u_v=NULL;
  std::vector<int> *flag_v_v=NULL;
  std::vector<int> *flag_w_v=NULL;
  std::vector<std::vector<double>> *wire_index_u_vv=NULL;
  std::vector<std::vector<double>> *wire_index_v_vv=NULL;
  std::vector<std::vector<double>> *wire_index_w_vv=NULL;
  std::vector<std::vector<double>> *wire_charge_u_vv=NULL;
  std::vector<std::vector<double>> *wire_charge_v_vv=NULL;
  std::vector<std::vector<double>> *wire_charge_w_vv=NULL;
  std::vector<std::vector<double>> *wire_charge_err_u_vv=NULL;
  std::vector<std::vector<double>> *wire_charge_err_v_vv=NULL;
  std::vector<std::vector<double>> *wire_charge_err_w_vv=NULL;

  std::vector<int> *cluster_id_v_nnbar=NULL;
  std::vector<int> *parent_cluster_id_v_nnbar=NULL;
  std::vector<int> *time_slice_v_nnbar=NULL;
  std::vector<double> *q_v_nnbar=NULL;
  std::vector<double> *uq_v_nnbar=NULL;
  std::vector<double> *vq_v_nnbar=NULL;
  std::vector<double> *wq_v_nnbar=NULL;
  std::vector<double> *udq_v_nnbar=NULL;
  std::vector<double> *vdq_v_nnbar=NULL;
  std::vector<double> *wdq_v_nnbar=NULL;
  std::vector<int> *nwire_u_v_nnbar=NULL;
  std::vector<int> *nwire_v_v_nnbar=NULL;
  std::vector<int> *nwire_w_v_nnbar=NULL;
  std::vector<int> *flag_u_v_nnbar=NULL;
  std::vector<int> *flag_v_v_nnbar=NULL;
  std::vector<int> *flag_w_v_nnbar=NULL;
  std::vector<std::vector<double>> *wire_index_u_vv_nnbar=NULL;
  std::vector<std::vector<double>> *wire_index_v_vv_nnbar=NULL;
  std::vector<std::vector<double>> *wire_index_w_vv_nnbar=NULL;
  std::vector<std::vector<double>> *wire_charge_u_vv_nnbar=NULL;
  std::vector<std::vector<double>> *wire_charge_v_vv_nnbar=NULL;
  std::vector<std::vector<double>> *wire_charge_w_vv_nnbar=NULL;
  std::vector<std::vector<double>> *wire_charge_err_u_vv_nnbar=NULL;
  std::vector<std::vector<double>> *wire_charge_err_v_vv_nnbar=NULL;
  std::vector<std::vector<double>> *wire_charge_err_w_vv_nnbar=NULL;
  


void study_cluster(){


  double flash_time = 100000.;
  int flash_id = 10000;
  int flash_runNo = 10000;
  int flash_subRunNo = 10000;
  int flash_eventNo = 10000;

  double flash_time_nnbar = 100000.;
  int flash_id_nnbar = 10000;
  int flash_runNo_nnbar = 10000;
  int flash_subRunNo_nnbar = 10000;
  int flash_eventNo_nnbar = 10000;


  TFile *fnew = new TFile ("out_study_cluster.root","recreate");
  tree_ext_flash->SetBranchAddress("flash_id",&flash_id);
  tree_ext_flash->SetBranchAddress("time",&flash_time);
  tree_ext_flash->SetBranchAddress("runNo",&flash_runNo);
  tree_ext_flash->SetBranchAddress("subRunNo",&flash_subRunNo);
  tree_ext_flash->SetBranchAddress("eventNo",&flash_eventNo);
  
  tree_nnbar_flash->SetBranchAddress("flash_id",&flash_id_nnbar);
  tree_nnbar_flash->SetBranchAddress("time",&flash_time_nnbar);
  tree_nnbar_flash->SetBranchAddress("runNo",&flash_runNo_nnbar);
  tree_nnbar_flash->SetBranchAddress("subRunNo",&flash_subRunNo_nnbar);
  tree_nnbar_flash->SetBranchAddress("eventNo",&flash_eventNo_nnbar);
  
  std::vector <int> runNo_nnbar_v;
  std::vector <int> subRunNo_nnbar_v;
  std::vector <int> eventNo_nnbar_v;
  std::vector <int> flash_id_nnbar_v;
  std::vector <double> flash_time_nnbar_v;
  //find out nnbar flash ids from flash tree
  //extrack extra flashes by comparing with ext / nnbar flashes
  for (int i=0; i<tree_nnbar_flash->GetEntries(); i++){
    tree_nnbar_flash->GetEntry(i);
    std::vector <double> temp_flash_v = {};

    for (int j=0; j<tree_ext_flash->GetEntries(); j++){
      tree_ext_flash->GetEntry(j);
      
      if (flash_runNo == flash_runNo_nnbar && flash_subRunNo == flash_subRunNo_nnbar && flash_eventNo == flash_eventNo_nnbar) {
	temp_flash_v.push_back(flash_time);
	//	std::cout << j << "v push back : " << flash_time << std::endl; 
      }
    }
    
    if (! (std::find(temp_flash_v.begin(), temp_flash_v.end(), flash_time_nnbar) !=temp_flash_v.end()) ){
	std::cout << i<<"-th entry, evtNo nnbar: "<< flash_eventNo_nnbar << ", ext flash time : " << flash_time << ", nnbar flash time : " << flash_time_nnbar<< std::endl;
	runNo_nnbar_v.push_back(flash_runNo_nnbar);
	subRunNo_nnbar_v.push_back(flash_subRunNo_nnbar);
	eventNo_nnbar_v.push_back(flash_eventNo_nnbar);
	flash_id_nnbar_v.push_back(flash_id_nnbar);
	flash_time_nnbar_v.push_back(flash_time_nnbar);
    } 
  }

  int tpc_cluster_id_nnbar = -1;
  int match_flash_id_nnbar = -10;
  int match_runNo_nnbar = -1;
  int match_subRunNo_nnbar = -1;
  int match_eventNo_nnbar = -1;
  
  tree_nnbar_match->SetBranchAddress("tpc_cluster_id",&tpc_cluster_id_nnbar);
  tree_nnbar_match->SetBranchAddress("flash_id",&match_flash_id_nnbar);
  tree_nnbar_match->SetBranchAddress("runNo",&match_runNo_nnbar);
  tree_nnbar_match->SetBranchAddress("subRunNo",&match_subRunNo_nnbar);
  tree_nnbar_match->SetBranchAddress("eventNo",&match_eventNo_nnbar);

  std::vector <int> match_runNo_nnbar_v;
  std::vector <int> match_subRunNo_nnbar_v;
  std::vector <int> match_eventNo_nnbar_v;
  std::vector <int> match_flash_id_nnbar_v;
  std::vector <int> match_tpc_cluster_id_nnbar_v;
  std::vector <double> match_flash_time_nnbar_v;
  //find out tpc_cluster_id associated with flash id from
  for (int i=0; i<tree_nnbar_match->GetEntries(); i++){
    tree_nnbar_match->GetEntry(i);
    for (int j=0; j<flash_id_nnbar_v.size(); j++){
      if(eventNo_nnbar_v.at(j) == match_eventNo_nnbar && runNo_nnbar_v.at(j) == match_runNo_nnbar && subRunNo_nnbar_v.at(j) == match_subRunNo_nnbar && flash_id_nnbar_v.at(j) == match_flash_id_nnbar){
	std::cout <<"flash_id : " <<flash_id_nnbar_v.at(j)<< " , match_flash_id_nnbar : "<< match_flash_id_nnbar << " , tpc_cluster_id_nnbar : "<< tpc_cluster_id_nnbar << std::endl;
	std::cout << "runNo : " << match_runNo_nnbar << " , subRunNo : " << match_subRunNo_nnbar << " , eventNo : " << match_eventNo_nnbar << std::endl;
	match_runNo_nnbar_v.push_back(match_runNo_nnbar);
	match_subRunNo_nnbar_v.push_back(match_subRunNo_nnbar);
	match_eventNo_nnbar_v.push_back(match_eventNo_nnbar);
	match_tpc_cluster_id_nnbar_v.push_back(tpc_cluster_id_nnbar);
	match_flash_time_nnbar_v.push_back(flash_time_nnbar_v.at(j));
	match_flash_id_nnbar_v.push_back(flash_id_nnbar_v.at(j));
      }
    }
  }

  std::vector <int> eval_entry_v;
  std::vector <int> eval_runNo_v;
  std::vector <int> eval_subRunNo_v;
  std::vector <int> eval_eventNo_v;
  std::vector <int> eval_cluster_id_v;
  std::vector <int> eval_flash_id_v;
  std::vector <double> eval_flash_time_v;
  int eval_run = -1;
  int eval_subrun = -1;
  int eval_event = -1;
  
  tree_nnbar_eval->SetBranchAddress("run",&eval_run);
  tree_nnbar_eval->SetBranchAddress("subrun",&eval_subrun);
  tree_nnbar_eval->SetBranchAddress("event",&eval_event);
  
  // go to Teval and get the entry number (T_eval entry number == TC entry number)
  for (int i=0; i<tree_nnbar_eval->GetEntries(); i++){
    tree_nnbar_eval->GetEntry(i);
    for (int j=0; j<match_tpc_cluster_id_nnbar_v.size(); j++){
      if(eval_run==match_runNo_nnbar_v.at(j) && eval_subrun==match_subRunNo_nnbar_v.at(j) && eval_event==match_eventNo_nnbar_v.at(j)){

	if (match_flash_time_nnbar_v.at(j)<1.){ //flash time for nnbar cluster ~ 0.453
	eval_entry_v.push_back(i);
	eval_runNo_v.push_back(eval_run);
	eval_subRunNo_v.push_back(eval_subrun);
	eval_eventNo_v.push_back(eval_event);
	eval_cluster_id_v.push_back(match_tpc_cluster_id_nnbar_v.at(j));
	std::cout << "eval entry: "<<i << ", run: "<<eval_run<<" , subrun: "<<eval_subrun<<" , event: "<<eval_event<<" , cl_id : "<<match_tpc_cluster_id_nnbar_v.at(j)<< std::endl;

	eval_flash_id_v.push_back(match_flash_id_nnbar_v.at(j));
	eval_flash_time_v.push_back(match_flash_time_nnbar_v.at(j));

	std::cout << "eval_flash_id : " << match_flash_id_nnbar_v.at(j) << " , eval_flash_time : " << match_flash_time_nnbar_v.at(j) << std::endl;
	}
	
      }
    }
  }
    

  // select nnbar cluster and plot things
  tree_nnbar_TC->SetBranchAddress("cluster_id",&cluster_id_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("parent_cluster_id",&parent_cluster_id_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("time_slice",&time_slice_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("q",&q_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("uq",&uq_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("vq",&vq_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("wq",&wq_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("udq",&udq_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("vdq",&vdq_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("wdq",&wdq_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("nwire_u",&nwire_u_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("nwire_v",&nwire_v_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("nwire_w",&nwire_w_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("flag_u",&flag_u_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("flag_v",&flag_v_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("flag_w",&flag_w_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("wire_index_u",&wire_index_u_vv_nnbar);
  tree_nnbar_TC->SetBranchAddress("wire_index_v",&wire_index_v_vv_nnbar);
  tree_nnbar_TC->SetBranchAddress("wire_index_w",&wire_index_w_vv_nnbar);
  tree_nnbar_TC->SetBranchAddress("wire_charge_u",&wire_charge_u_vv_nnbar);
  tree_nnbar_TC->SetBranchAddress("wire_charge_v",&wire_charge_v_vv_nnbar);
  tree_nnbar_TC->SetBranchAddress("wire_charge_w",&wire_charge_w_vv_nnbar);
  tree_nnbar_TC->SetBranchAddress("wire_charge_err_u",&wire_charge_err_u_vv_nnbar);
  tree_nnbar_TC->SetBranchAddress("wire_charge_err_v",&wire_charge_err_v_vv_nnbar);
  tree_nnbar_TC->SetBranchAddress("wire_charge_err_w",&wire_charge_err_w_vv_nnbar);
  
  TH1F *h_cluster_id_nnbar = new TH1F("h_cluster_id_nnbar","h_cluster_id_nnbar",240,0,240);
  TH1F *h_parent_cluster_id_nnbar = new TH1F("h_parent_cluster_id_nnbar","h_parent_cluster_id_nnbar",240,0,240);
  TH1F *h_time_slice_nnbar = new TH1F("h_time_slice_nnbar","h_time_slice_nnbar",40,0,2400);
  TH1F *h_q_nnbar = new TH1F("h_q_nnbar","h_q_nnbar",50,0,30000);
  TH1F *h_uq_nnbar = new TH1F("h_uq_nnbar","h_uq_nnbar",50,0,100000);
  TH1F *h_vq_nnbar = new TH1F("h_vq_nnbar","h_vq_nnbar",50,0,100000);
  TH1F *h_wq_nnbar = new TH1F("h_wq_nnbar","h_wq_nnbar",50,0,100000);
  TH1F *h_udq_nnbar = new TH1F("h_udq_nnbar","h_udq_nnbar",50,0,10000);
  TH1F *h_vdq_nnbar = new TH1F("h_vdq_nnbar","h_vdq_nnbar",50,0,10000);
  TH1F *h_wdq_nnbar = new TH1F("h_wdq_nnbar","h_wdq_nnbar",50,0,2500);
  TH1F *h_nwire_u_nnbar = new TH1F("h_nwire_u_nnbar","h_nwire_u_nnbar",50,0,50);
  TH1F *h_nwire_v_nnbar = new TH1F("h_nwire_v_nnbar","h_nwire_v_nnbar",50,0,50);
  TH1F *h_nwire_w_nnbar = new TH1F("h_nwire_w_nnbar","h_nwire_w_nnbar",50,0,50);
  TH1F *h_wire_index_u_nnbar = new TH1F("h2_wire_index_u_nnbar","h2_wire_index_u_nnbar",240,0,2400);
  TH1F *h_wire_index_v_nnbar    = new TH1F("h2_wire_index_v_nnbar","h2_wire_index_v_nnbar",240,0,2400);
  TH1F *h_wire_index_w_nnbar  = new TH1F("h2_wire_index_w_nnbar","h2_wire_index_w_nnbar",350,0,3500);

  TH1F *h_wire_charge_u_nnbar   = new TH1F("h2_wire_charge_u_nnbar","h2_wire_charge_u_nnbar",50,0,50000);
  TH1F *h_wire_charge_v_nnbar  = new TH1F("h2_wire_charge_v_nnbar","h2_wire_charge_v_nnbar",50,0,50000);
  TH1F *h_wire_charge_w_nnbar  = new TH1F("h2_wire_charge_w_nnbar","h2_wire_charge_w_nnbar",50,0,50000);
  TH1F *h_wire_charge_err_u_nnbar       = new TH1F("h2_wire_charge_err_u_nnbar","h2_wire_charge_err_u_nnbar",50,0,2500);
  TH1F *h_wire_charge_err_v_nnbar  = new TH1F("h2_wire_charge_err_v_nnbar","h2_wire_charge_err_v_nnbar",50,0,4000);
  TH1F *h_wire_charge_err_w_nnbar  = new TH1F("h2_wire_charge_err_w_nnbar","h2_wire_charge_err_w_nnbar",20,0,400);
  TH1F *h_extent_x_nnbar  = new TH1F("h_extent_x_nnbar","h_extent_x_nnbar",20,0,400);
  TH1F *h_extent_y_nnbar = new TH1F("h_extent_y_nnbar","h_extent_y_nnbar",20,0,400);

  TH2F *h2_extent_xy_nnbar = new TH2F("h2_extent_xy_nnbar","h2_extent_xy_nnbar",20,0,400,20,0,400);
  
  TH1F *h_cluster_id_nnbar_cluster[80] = {NULL};
  TH1F *h_parent_cluster_id_nnbar_cluster[80] = {NULL};
  TH1F *h_time_slice_nnbar_cluster[80] = {NULL};
  TH1F *h_q_nnbar_cluster[80] = {NULL};
  TH1F *h_uq_nnbar_cluster[80] = {NULL};
  TH1F *h_vq_nnbar_cluster[80] = {NULL};
  TH1F *h_wq_nnbar_cluster[80] = {NULL};
  TH1F *h_udq_nnbar_cluster[80] = {NULL};
  TH1F *h_vdq_nnbar_cluster[80] = {NULL};
  TH1F *h_wdq_nnbar_cluster[80] = {NULL};
  TH1F *h_nwire_u_nnbar_cluster[80] = {NULL};
  TH1F *h_nwire_v_nnbar_cluster[80] = {NULL};
  TH1F *h_nwire_w_nnbar_cluster[80] = {NULL};
  TH1F *h_wire_index_u_nnbar_cluster[80] = {NULL};
  TH1F *h_wire_index_v_nnbar_cluster[80] = {NULL};
  TH1F *h_wire_index_w_nnbar_cluster[80] = {NULL};
  TH1F *h_wire_charge_u_nnbar_cluster[80] = {NULL};
  TH1F *h_wire_charge_v_nnbar_cluster[80] = {NULL};
  TH1F *h_wire_charge_w_nnbar_cluster[80] = {NULL};
  TH1F *h_wire_charge_err_u_nnbar_cluster[80] = {NULL};
  TH1F *h_wire_charge_err_v_nnbar_cluster[80] = {NULL}; 
  TH1F *h_wire_charge_err_w_nnbar_cluster[80] = {NULL}; 
  TH2F *h2_time_w_charge_nnbar_cluster[80] = {NULL};
  //new TH2F("h2_time_w_charge_nnbar", "h2_time_w_charge_nnbar",3500,0,3500,2400,0,2400);
  
  int nnbar_entries = tree_nnbar_TC->GetEntries();
  std::cout << "nnbar_entries: " << nnbar_entries << std::endl;
  for (int i_eval=0; i_eval<eval_entry_v.size(); i_eval++){
    tree_nnbar_TC->GetEntry(eval_entry_v.at(i_eval));

    int extent_x_min = 10000;
    int extent_x_max = 0;

    int extent_y_min = 10000;
    int extent_y_max = 0;


    TString histoname = TString::Format("_%d", i_eval);

    h_cluster_id_nnbar_cluster[i_eval] = new TH1F("h_cluster_id_nnbar"+histoname,"h_cluster_id_nnbar"+histoname,240,0,240);
    h_parent_cluster_id_nnbar_cluster[i_eval] = new TH1F("h_parent_cluster_id_nnbar_cluster"+histoname,"h_parent_cluster_id_nnbar_cluster"+histoname,240,0,240);
    h_time_slice_nnbar_cluster[i_eval] = new TH1F("h_time_slice_nnbar_cluster"+histoname,"h_time_slice_nnbar_cluster"+histoname,40,0,2400);    
    h_q_nnbar_cluster[i_eval] = new TH1F("h_q_nnbar_cluster"+histoname,"h_q_nnbar_cluster"+histoname,50,0,30000);
    h_uq_nnbar_cluster[i_eval] = new TH1F("h_uq_nnbar_cluster"+histoname,"h_uq_nnbar_cluster"+histoname,50,0,100000);
    h_vq_nnbar_cluster[i_eval] = new TH1F("h_vq_nnbar_cluster"+histoname,"h_vq_nnbar_cluster"+histoname,50,0,100000);
    h_wq_nnbar_cluster[i_eval] = new TH1F("h_wq_nnbar_cluster"+histoname,"h_wq_nnbar_cluster"+histoname,50,0,100000);
    h_udq_nnbar_cluster[i_eval] = new TH1F("h_udq_nnbar_cluster"+histoname,"h_udq_nnbar_cluster"+histoname,50,0,10000);
    h_vdq_nnbar_cluster[i_eval] = new TH1F("h_vdq_nnbar_cluster"+histoname,"h_vdq_nnbar_cluster"+histoname,50,0,10000);
    h_wdq_nnbar_cluster[i_eval] = new TH1F("h_wdq_nnbar_cluster"+histoname,"h_wdq_nnbar_cluster"+histoname,50,0,2500);
    h_nwire_u_nnbar_cluster[i_eval] = new TH1F("h_nwire_u_nnbar_cluster"+histoname,"h_nwire_u_nnbar_cluster"+histoname,50,0,50);
    h_nwire_v_nnbar_cluster[i_eval] = new TH1F("h_nwire_v_nnbar_cluster"+histoname,"h_nwire_v_nnbar_cluster"+histoname,50,0,50);
    h_nwire_w_nnbar_cluster[i_eval] = new TH1F("h_nwire_w_nnbar_cluster"+histoname,"h_nwire_w_nnbar_cluster"+histoname,50,0,50);
    h_wire_index_u_nnbar_cluster[i_eval] = new TH1F("h2_wire_index_u_nnbar_cluster"+histoname,"h2_wire_index_u_nnbar_cluster"+histoname,240,0,2400);
    h_wire_index_v_nnbar_cluster[i_eval] = new TH1F("h2_wire_index_v_nnbar_cluster"+histoname,"h2_wire_index_v_nnbar_cluster"+histoname,240,0,2400);
    h_wire_index_w_nnbar_cluster[i_eval] = new TH1F("h2_wire_index_w_nnbar_cluster"+histoname,"h2_wire_index_w_nnbar_cluster"+histoname,350,0,3500);

    h_wire_charge_u_nnbar_cluster[i_eval] = new TH1F("h2_wire_charge_u_nnbar_cluster"+histoname,"h2_wire_charge_u_nnbar_cluster"+histoname,50,0,50000);
    h_wire_charge_v_nnbar_cluster[i_eval] = new TH1F("h2_wire_charge_v_nnbar_cluster"+histoname,"h2_wire_charge_v_nnbar_cluster"+histoname,50,0,50000);
    h_wire_charge_w_nnbar_cluster[i_eval] = new TH1F("h2_wire_charge_w_nnbar_cluster"+histoname,"h2_wire_charge_w_nnbar_cluster"+histoname,50,0,50000);
    h_wire_charge_err_u_nnbar_cluster[i_eval] = new TH1F("h2_wire_charge_err_u_nnbar_cluster"+histoname,"h2_wire_charge_err_u_nnbar_cluster"+histoname,50,0,2500);
    h_wire_charge_err_v_nnbar_cluster[i_eval] = new TH1F("h2_wire_charge_err_v_nnbar_cluster"+histoname,"h2_wire_charge_err_v_nnbar_cluster"+histoname,50,0,4000);
    h_wire_charge_err_w_nnbar_cluster[i_eval] = new TH1F("h2_wire_charge_err_w_nnbar_cluster"+histoname,"h2_wire_charge_err_w_nnbar_cluster"+histoname,20,0,400);
    
    h2_time_w_charge_nnbar_cluster[i_eval] = new TH2F ("h2_time_w_charge_nnbar_cluster"+histoname,"h2_time_w_charge_nnbar_cluster"+histoname,3500,0,3500,2400,0,2400);
    
    for (int i_clu=0; i_clu<cluster_id_v_nnbar->size(); i_clu++){      
      if (cluster_id_v_nnbar->at(i_clu) == eval_cluster_id_v.at(i_eval)){
	
	h_cluster_id_nnbar_cluster[i_eval]->Fill(cluster_id_v_nnbar->at(i_clu));
	h_parent_cluster_id_nnbar_cluster[i_eval]->Fill(parent_cluster_id_v_nnbar->at(i_clu));
	h_time_slice_nnbar_cluster[i_eval]->Fill(time_slice_v_nnbar->at(i_clu));

	if (time_slice_v_nnbar->at(i_clu) < extent_y_min)
	  {
	    extent_y_min = time_slice_v_nnbar->at(i_clu);
	    std::cout << "extent_y_min update: "<<extent_y_min << std::endl; 
	  }
	if (extent_y_max < time_slice_v_nnbar->at(i_clu)) {
	  extent_y_max = time_slice_v_nnbar->at(i_clu);
	  std::cout << "extent_y_max update: "<<extent_y_max << std::endl;
	}

	
	h_q_nnbar_cluster[i_eval]->Fill(q_v_nnbar->at(i_clu));
	h_uq_nnbar_cluster[i_eval]->Fill(uq_v_nnbar->at(i_clu));
	h_vq_nnbar_cluster[i_eval]->Fill(vq_v_nnbar->at(i_clu));
	h_wq_nnbar_cluster[i_eval]->Fill(wq_v_nnbar->at(i_clu));
	h_udq_nnbar_cluster[i_eval]->Fill(udq_v_nnbar->at(i_clu));
	h_vdq_nnbar_cluster[i_eval]->Fill(vdq_v_nnbar->at(i_clu));
        h_wdq_nnbar_cluster[i_eval]->Fill(wdq_v_nnbar->at(i_clu));
        h_nwire_u_nnbar_cluster[i_eval]->Fill(nwire_u_v_nnbar->at(i_clu));
	h_nwire_v_nnbar_cluster[i_eval]->Fill(nwire_v_v_nnbar->at(i_clu));
	h_nwire_w_nnbar_cluster[i_eval]->Fill(nwire_w_v_nnbar->at(i_clu));
	for(int k=0; k< wire_index_u_vv_nnbar->at(i_clu).size(); k++)	h_wire_index_u_nnbar_cluster[i_eval]->Fill(wire_index_u_vv_nnbar->at(i_clu).at(k)); 
	for(int k=0; k< wire_index_v_vv_nnbar->at(i_clu).size(); k++) h_wire_index_v_nnbar_cluster[i_eval]->Fill(wire_index_v_vv_nnbar->at(i_clu).at(k));    
	for(int k=0; k< wire_index_w_vv_nnbar->at(i_clu).size(); k++)        h_wire_index_w_nnbar_cluster[i_eval]->Fill(wire_index_w_vv_nnbar->at(i_clu).at(k));    

	for(int k=0; k< wire_index_w_vv_nnbar->at(i_clu).size(); k++)        {
	  h_wire_index_w_nnbar_cluster[i_eval]->Fill(wire_index_w_vv_nnbar->at(i_clu).at(k));
	  if (wire_index_w_vv_nnbar->at(i_clu).at(k) < extent_x_min) {extent_x_min = wire_index_w_vv_nnbar->at(i_clu).at(k);
	    std::cout << "extent_ x_min update : " << extent_x_min << std::endl;}
	  if (extent_x_max < wire_index_w_vv_nnbar->at(i_clu).at(k)) {extent_x_max = wire_index_w_vv_nnbar->at(i_clu).at(k);
	    std::cout << "extent_x_max update : " << extent_x_max << std::endl;
	  }
	}
	
	for(int k=0; k< wire_charge_u_vv_nnbar->at(i_clu).size(); k++)        h_wire_charge_u_nnbar_cluster[i_eval]->Fill(wire_charge_u_vv_nnbar->at(i_clu).at(k));    
	for(int k=0; k< wire_charge_v_vv_nnbar->at(i_clu).size(); k++)        h_wire_charge_v_nnbar_cluster[i_eval]->Fill(wire_charge_v_vv_nnbar->at(i_clu).at(k));    
	for(int k=0; k< wire_charge_w_vv_nnbar->at(i_clu).size(); k++)	h_wire_charge_w_nnbar_cluster[i_eval]->Fill(wire_charge_w_vv_nnbar->at(i_clu).at(k));
	for(int k=0; k< wire_charge_err_u_vv_nnbar->at(i_clu).size(); k++)  h_wire_charge_err_u_nnbar_cluster[i_eval]->Fill(wire_charge_err_u_vv_nnbar->at(i_clu).at(k)); 
	for(int k=0; k< wire_charge_err_v_vv_nnbar->at(i_clu).size(); k++)   h_wire_charge_err_v_nnbar_cluster[i_eval]->Fill(wire_charge_err_v_vv_nnbar->at(i_clu).at(k)); 
	for(int k=0; k< wire_charge_err_w_vv_nnbar->at(i_clu).size(); k++)	h_wire_charge_err_w_nnbar_cluster[i_eval]->Fill(wire_charge_err_w_vv_nnbar->at(i_clu).at(k));

	for(int k=0; k< wire_charge_w_vv_nnbar->at(i_clu).size(); k++){
	  h2_time_w_charge_nnbar_cluster[i_eval]->Fill(wire_index_w_vv_nnbar->at(i_clu).at(k), time_slice_v_nnbar->at(i_clu),wire_charge_w_vv_nnbar->at(i_clu).at(k));
	}









	
	h_cluster_id_nnbar->Fill(cluster_id_v_nnbar->at(i_clu));
	h_parent_cluster_id_nnbar->Fill(parent_cluster_id_v_nnbar->at(i_clu));
	h_time_slice_nnbar->Fill(time_slice_v_nnbar->at(i_clu));
	
	h_q_nnbar->Fill(q_v_nnbar->at(i_clu));
	h_uq_nnbar->Fill(uq_v_nnbar->at(i_clu));
	h_vq_nnbar->Fill(vq_v_nnbar->at(i_clu));
	h_wq_nnbar->Fill(wq_v_nnbar->at(i_clu));
	h_udq_nnbar->Fill(udq_v_nnbar->at(i_clu));
	h_vdq_nnbar->Fill(vdq_v_nnbar->at(i_clu));
        h_wdq_nnbar->Fill(wdq_v_nnbar->at(i_clu));
        h_nwire_u_nnbar->Fill(nwire_u_v_nnbar->at(i_clu));
	h_nwire_v_nnbar->Fill(nwire_v_v_nnbar->at(i_clu));
	h_nwire_w_nnbar->Fill(nwire_w_v_nnbar->at(i_clu));
	for(int k=0; k< wire_index_u_vv_nnbar->at(i_clu).size(); k++)	h_wire_index_u_nnbar->Fill(wire_index_u_vv_nnbar->at(i_clu).at(k)); 
	for(int k=0; k< wire_index_v_vv_nnbar->at(i_clu).size(); k++) h_wire_index_v_nnbar->Fill(wire_index_v_vv_nnbar->at(i_clu).at(k));    
	for(int k=0; k< wire_index_w_vv_nnbar->at(i_clu).size(); k++)        h_wire_index_w_nnbar->Fill(wire_index_w_vv_nnbar->at(i_clu).at(k));    
	for(int k=0; k< wire_charge_u_vv_nnbar->at(i_clu).size(); k++)        h_wire_charge_u_nnbar->Fill(wire_charge_u_vv_nnbar->at(i_clu).at(k));    
	for(int k=0; k< wire_charge_v_vv_nnbar->at(i_clu).size(); k++)        h_wire_charge_v_nnbar->Fill(wire_charge_v_vv_nnbar->at(i_clu).at(k));    
	for(int k=0; k< wire_charge_w_vv_nnbar->at(i_clu).size(); k++)	h_wire_charge_w_nnbar->Fill(wire_charge_w_vv_nnbar->at(i_clu).at(k)); 
	for(int k=0; k< wire_charge_err_u_vv_nnbar->at(i_clu).size(); k++)  h_wire_charge_err_u_nnbar->Fill(wire_charge_err_u_vv_nnbar->at(i_clu).at(k)); 
	for(int k=0; k< wire_charge_err_v_vv_nnbar->at(i_clu).size(); k++)   h_wire_charge_err_v_nnbar->Fill(wire_charge_err_v_vv_nnbar->at(i_clu).at(k)); 
	for(int k=0; k< wire_charge_err_w_vv_nnbar->at(i_clu).size(); k++)	h_wire_charge_err_w_nnbar->Fill(wire_charge_err_w_vv_nnbar->at(i_clu).at(k));      
      }
    }

    h_extent_x_nnbar->Fill(extent_x_max-extent_x_min);
    h_extent_y_nnbar->Fill(extent_y_max-extent_y_min);
    h2_extent_xy_nnbar->Fill(extent_x_max-extent_x_min, extent_y_max-extent_y_min);

    
  }

  tree_ext_TC->SetBranchAddress("cluster_id",&cluster_id_v);
  tree_ext_TC->SetBranchAddress("parent_cluster_id",&parent_cluster_id_v);
  tree_ext_TC->SetBranchAddress("time_slice",&time_slice_v);
  tree_ext_TC->SetBranchAddress("q",&q_v);
  tree_ext_TC->SetBranchAddress("uq",&uq_v);
  tree_ext_TC->SetBranchAddress("vq",&vq_v);
  tree_ext_TC->SetBranchAddress("wq",&wq_v);
  tree_ext_TC->SetBranchAddress("udq",&udq_v);
  tree_ext_TC->SetBranchAddress("vdq",&vdq_v);
  tree_ext_TC->SetBranchAddress("wdq",&wdq_v);
  tree_ext_TC->SetBranchAddress("nwire_u",&nwire_u_v);
  tree_ext_TC->SetBranchAddress("nwire_v",&nwire_v_v);
  tree_ext_TC->SetBranchAddress("nwire_w",&nwire_w_v);
  tree_ext_TC->SetBranchAddress("flag_u",&flag_u_v);
  tree_ext_TC->SetBranchAddress("flag_v",&flag_v_v);
  tree_ext_TC->SetBranchAddress("flag_w",&flag_w_v);
  tree_ext_TC->SetBranchAddress("wire_index_u",&wire_index_u_vv);
  tree_ext_TC->SetBranchAddress("wire_index_v",&wire_index_v_vv);
  tree_ext_TC->SetBranchAddress("wire_index_w",&wire_index_w_vv);
  tree_ext_TC->SetBranchAddress("wire_charge_u",&wire_charge_u_vv);
  tree_ext_TC->SetBranchAddress("wire_charge_v",&wire_charge_v_vv);
  tree_ext_TC->SetBranchAddress("wire_charge_w",&wire_charge_w_vv);
  tree_ext_TC->SetBranchAddress("wire_charge_err_u",&wire_charge_err_u_vv);
  tree_ext_TC->SetBranchAddress("wire_charge_err_v",&wire_charge_err_v_vv);
  tree_ext_TC->SetBranchAddress("wire_charge_err_w",&wire_charge_err_w_vv);

  TH1F *h_cluster_id_ext = new TH1F("h_cluster_id_ext","h_cluster_id_ext",240,0,240);
  TH1F *h_parent_cluster_id_ext = new TH1F("h_parent_cluster_id_ext","h_parent_cluster_id_ext",240,0,240);
  TH1F *h_time_slice_ext = new TH1F("h_time_slice_ext","h_time_slice_ext",40,0,2400);
  TH1F *h_q_ext = new TH1F("h_q_ext","h_q_ext",50,0,30000);
  TH1F *h_uq_ext = new TH1F("h_uq_ext","h_uq_ext",50,0,100000);
  TH1F *h_vq_ext = new TH1F("h_vq_ext","h_vq_ext",50,0,100000);
  TH1F *h_wq_ext = new TH1F("h_wq_ext","h_wq_ext",50,0,100000);
  TH1F *h_udq_ext = new TH1F("h_udq_ext","h_udq_ext",50,0,10000);
  TH1F *h_vdq_ext = new TH1F("h_vdq_ext","h_vdq_ext",50,0,10000);
  TH1F *h_wdq_ext = new TH1F("h_wdq_ext","h_wdq_ext",50,0,2500);
  TH1F *h_nwire_u_ext = new TH1F("h_nwire_u_ext","h_nwire_u_ext",50,0,50);
  TH1F *h_nwire_v_ext = new TH1F("h_nwire_v_ext","h_nwire_v_ext",50,0,50);
  TH1F *h_nwire_w_ext = new TH1F("h_nwire_w_ext","h_nwire_w_ext",50,0,50);
  TH1F *h_wire_index_u_ext = new TH1F("h2_wire_index_u_ext","h2_wire_index_u_ext",240,0,2400);
  TH1F *h_wire_index_v_ext    = new TH1F("h2_wire_index_v_ext","h2_wire_index_v_ext",240,0,2400);
  TH1F *h_wire_index_w_ext  = new TH1F("h2_wire_index_w_ext","h2_wire_index_w_ext",350,0,3500);

  TH1F *h_wire_charge_u_ext   = new TH1F("h2_wire_charge_u_ext","h2_wire_charge_u_ext",50,0,50000);
  TH1F *h_wire_charge_v_ext  = new TH1F("h2_wire_charge_v_ext","h2_wire_charge_v_ext",50,0,50000);
  TH1F *h_wire_charge_w_ext  = new TH1F("h2_wire_charge_w_ext","h2_wire_charge_w_ext",50,0,50000);
  TH1F *h_wire_charge_err_u_ext       = new TH1F("h2_wire_charge_err_u_ext","h2_wire_charge_err_u_ext",50,0,2500);
  TH1F *h_wire_charge_err_v_ext  = new TH1F("h2_wire_charge_err_v_ext","h2_wire_charge_err_v_ext",50,0,4000);
  TH1F *h_wire_charge_err_w_ext  = new TH1F("h2_wire_charge_err_w_ext","h2_wire_charge_err_w_ext",20,0,400);
  TH1F *h_extent_x_ext  = new TH1F("h_extent_x_ext","h_extent_x_ext",20,0,400);
  TH1F *h_extent_y_ext = new TH1F("h_extent_y_ext","h_extent_y_ext",20,0,400);

  TH2F *h2_extent_xy_ext = new TH2F("h2_extent_xy_ext","h2_extent_xy_ext",20,0,400,20,0,400);
  
  TH1F *h_cluster_id_ext_cluster[80] = {NULL};
  TH1F *h_parent_cluster_id_ext_cluster[80] = {NULL};
  TH1F *h_time_slice_ext_cluster[80] = {NULL};
  TH1F *h_q_ext_cluster[80] = {NULL};
  TH1F *h_uq_ext_cluster[80] = {NULL};
  TH1F *h_vq_ext_cluster[80] = {NULL};
  TH1F *h_wq_ext_cluster[80] = {NULL};
  TH1F *h_udq_ext_cluster[80] = {NULL};
  TH1F *h_vdq_ext_cluster[80] = {NULL};
  TH1F *h_wdq_ext_cluster[80] = {NULL};
  TH1F *h_nwire_u_ext_cluster[80] = {NULL};
  TH1F *h_nwire_v_ext_cluster[80] = {NULL};
  TH1F *h_nwire_w_ext_cluster[80] = {NULL};
  TH1F *h_wire_index_u_ext_cluster[80] = {NULL};
  TH1F *h_wire_index_v_ext_cluster[80] = {NULL};
  TH1F *h_wire_index_w_ext_cluster[80] = {NULL};
  TH1F *h_wire_charge_u_ext_cluster[80] = {NULL};
  TH1F *h_wire_charge_v_ext_cluster[80] = {NULL};
  TH1F *h_wire_charge_w_ext_cluster[80] = {NULL};
  TH1F *h_wire_charge_err_u_ext_cluster[80] = {NULL};
  TH1F *h_wire_charge_err_v_ext_cluster[80] = {NULL}; 
  TH1F *h_wire_charge_err_w_ext_cluster[80] = {NULL}; 
  TH2F *h2_time_w_charge_ext_cluster[80] = {NULL};
  
  int ext_entries = tree_ext_TC->GetEntries();
  std::cout << "ext_entries: " << ext_entries << std::endl;
  
  for (int i_eval=0; i_eval<eval_entry_v.size(); i_eval++){

    int extent_x_min = 10000;
    int extent_x_max = 0;

    int extent_y_min = 10000;
    int extent_y_max = 0;
    std::cout << "i_eval : " <<i_eval << " , get entry " << eval_entry_v.at(i_eval) << std::endl;   
    tree_ext_TC->GetEntry(eval_entry_v.at(i_eval));
  
    TString histoname = TString::Format("_%d", i_eval);

    h_cluster_id_ext_cluster[i_eval] = new TH1F("h_cluster_id_ext"+histoname,"h_cluster_id_ext"+histoname,240,0,240);
    h_parent_cluster_id_ext_cluster[i_eval] = new TH1F("h_parent_cluster_id_ext_cluster"+histoname,"h_parent_cluster_id_ext_cluster"+histoname,240,0,240);
    h_time_slice_ext_cluster[i_eval] = new TH1F("h_time_slice_ext_cluster"+histoname,"h_time_slice_ext_cluster"+histoname,40,0,2400);    
    h_q_ext_cluster[i_eval] = new TH1F("h_q_ext_cluster"+histoname,"h_q_ext_cluster"+histoname,50,0,30000);
    h_uq_ext_cluster[i_eval] = new TH1F("h_uq_ext_cluster"+histoname,"h_uq_ext_cluster"+histoname,50,0,100000);
    h_vq_ext_cluster[i_eval] = new TH1F("h_vq_ext_cluster"+histoname,"h_vq_ext_cluster"+histoname,50,0,100000);
    h_wq_ext_cluster[i_eval] = new TH1F("h_wq_ext_cluster"+histoname,"h_wq_ext_cluster"+histoname,50,0,100000);
    h_udq_ext_cluster[i_eval] = new TH1F("h_udq_ext_cluster"+histoname,"h_udq_ext_cluster"+histoname,50,0,10000);
    h_vdq_ext_cluster[i_eval] = new TH1F("h_vdq_ext_cluster"+histoname,"h_vdq_ext_cluster"+histoname,50,0,10000);
    h_wdq_ext_cluster[i_eval] = new TH1F("h_wdq_ext_cluster"+histoname,"h_wdq_ext_cluster"+histoname,50,0,2500);
    h_nwire_u_ext_cluster[i_eval] = new TH1F("h_nwire_u_ext_cluster"+histoname,"h_nwire_u_ext_cluster"+histoname,50,0,50);
    h_nwire_v_ext_cluster[i_eval] = new TH1F("h_nwire_v_ext_cluster"+histoname,"h_nwire_v_ext_cluster"+histoname,50,0,50);
    h_nwire_w_ext_cluster[i_eval] = new TH1F("h_nwire_w_ext_cluster"+histoname,"h_nwire_w_ext_cluster"+histoname,50,0,50);
    h_wire_index_u_ext_cluster[i_eval] = new TH1F("h2_wire_index_u_ext_cluster"+histoname,"h2_wire_index_u_ext_cluster"+histoname,240,0,2400);
    h_wire_index_v_ext_cluster[i_eval] = new TH1F("h2_wire_index_v_ext_cluster"+histoname,"h2_wire_index_v_ext_cluster"+histoname,240,0,2400);
    h_wire_index_w_ext_cluster[i_eval] = new TH1F("h2_wire_index_w_ext_cluster"+histoname,"h2_wire_index_w_ext_cluster"+histoname,350,0,3500);

    h_wire_charge_u_ext_cluster[i_eval] = new TH1F("h2_wire_charge_u_ext_cluster"+histoname,"h2_wire_charge_u_ext_cluster"+histoname,50,0,50000);
    h_wire_charge_v_ext_cluster[i_eval] = new TH1F("h2_wire_charge_v_ext_cluster"+histoname,"h2_wire_charge_v_ext_cluster"+histoname,50,0,50000);
    h_wire_charge_w_ext_cluster[i_eval] = new TH1F("h2_wire_charge_w_ext_cluster"+histoname,"h2_wire_charge_w_ext_cluster"+histoname,50,0,50000);
    h_wire_charge_err_u_ext_cluster[i_eval] = new TH1F("h2_wire_charge_err_u_ext_cluster"+histoname,"h2_wire_charge_err_u_ext_cluster"+histoname,50,0,2500);
    h_wire_charge_err_v_ext_cluster[i_eval] = new TH1F("h2_wire_charge_err_v_ext_cluster"+histoname,"h2_wire_charge_err_v_ext_cluster"+histoname,50,0,4000);
    h_wire_charge_err_w_ext_cluster[i_eval] = new TH1F("h2_wire_charge_err_w_ext_cluster"+histoname,"h2_wire_charge_err_w_ext_cluster"+histoname,20,0,400);

    h2_time_w_charge_ext_cluster[i_eval] = new TH2F ("h2_time_w_charge_ext_cluster"+histoname,"h2_time_w_charge_ext_cluster"+histoname,3500,0,3500,2400,0,2400);

    for (int i_clu=0; i_clu<cluster_id_v->size(); i_clu++){
      
      if (cluster_id_v->at(i_clu) == eval_cluster_id_v.at(i_eval)){

	h_cluster_id_ext_cluster[i_eval]->Fill(cluster_id_v->at(i_clu));
	h_parent_cluster_id_ext_cluster[i_eval]->Fill(parent_cluster_id_v->at(i_clu));
	h_time_slice_ext_cluster[i_eval]->Fill(time_slice_v->at(i_clu));
	
	if (time_slice_v->at(i_clu) < extent_y_min)
	  {
	    extent_y_min = time_slice_v->at(i_clu);
	    std::cout << "extent_y_min update: "<<extent_y_min << std::endl; 
	  }
	if (extent_y_max < time_slice_v->at(i_clu)) {
	  extent_y_max = time_slice_v->at(i_clu);
	  std::cout << "extent_y_max update: "<<extent_y_max << std::endl;
	}
	h_q_ext_cluster[i_eval]->Fill(q_v->at(i_clu));
	h_uq_ext_cluster[i_eval]->Fill(uq_v->at(i_clu));
	h_vq_ext_cluster[i_eval]->Fill(vq_v->at(i_clu));
	h_wq_ext_cluster[i_eval]->Fill(wq_v->at(i_clu));
	h_udq_ext_cluster[i_eval]->Fill(udq_v->at(i_clu));
	h_vdq_ext_cluster[i_eval]->Fill(vdq_v->at(i_clu));
        h_wdq_ext_cluster[i_eval]->Fill(wdq_v->at(i_clu));
        h_nwire_u_ext_cluster[i_eval]->Fill(nwire_u_v->at(i_clu));
	h_nwire_v_ext_cluster[i_eval]->Fill(nwire_v_v->at(i_clu));
	h_nwire_w_ext_cluster[i_eval]->Fill(nwire_w_v->at(i_clu));
	
	for(int k=0; k< wire_index_u_vv->at(i_clu).size(); k++) h_wire_index_u_ext_cluster[i_eval]->Fill(wire_index_u_vv->at(i_clu).at(k));
	for(int k=0; k< wire_index_v_vv->at(i_clu).size(); k++) h_wire_index_v_ext_cluster[i_eval]->Fill(wire_index_v_vv->at(i_clu).at(k));    
	for(int k=0; k< wire_index_w_vv->at(i_clu).size(); k++)        {
	  h_wire_index_w_ext_cluster[i_eval]->Fill(wire_index_w_vv->at(i_clu).at(k));
	  
	  if (wire_index_w_vv->at(i_clu).at(k) < extent_x_min) {extent_x_min = wire_index_w_vv->at(i_clu).at(k);
	    std::cout << "extent_ x_min update : " << extent_x_min << std::endl;}
	  
	  if (extent_x_max < wire_index_w_vv->at(i_clu).at(k)) {extent_x_max = wire_index_w_vv->at(i_clu).at(k);
	    std::cout << "extent_x_max update : " << extent_x_max << std::endl;
	  }

	}
	for(int k=0; k< wire_charge_u_vv->at(i_clu).size(); k++)        h_wire_charge_u_ext_cluster[i_eval]->Fill(wire_charge_u_vv->at(i_clu).at(k));    
	for(int k=0; k< wire_charge_v_vv->at(i_clu).size(); k++)        h_wire_charge_v_ext_cluster[i_eval]->Fill(wire_charge_v_vv->at(i_clu).at(k));    
	for(int k=0; k< wire_charge_w_vv->at(i_clu).size(); k++)	h_wire_charge_w_ext_cluster[i_eval]->Fill(wire_charge_w_vv->at(i_clu).at(k)); 
	for(int k=0; k< wire_charge_err_u_vv->at(i_clu).size(); k++)  h_wire_charge_err_u_ext_cluster[i_eval]->Fill(wire_charge_err_u_vv->at(i_clu).at(k)); 
	for(int k=0; k< wire_charge_err_v_vv->at(i_clu).size(); k++)   h_wire_charge_err_v_ext_cluster[i_eval]->Fill(wire_charge_err_v_vv->at(i_clu).at(k)); 
	for(int k=0; k< wire_charge_err_w_vv->at(i_clu).size(); k++)	h_wire_charge_err_w_ext_cluster[i_eval]->Fill(wire_charge_err_w_vv->at(i_clu).at(k));

	for(int k=0; k< wire_charge_w_vv->at(i_clu).size(); k++){
	  h2_time_w_charge_ext_cluster[i_eval]->Fill(wire_index_w_vv->at(i_clu).at(k), time_slice_v->at(i_clu), wire_charge_w_vv->at(i_clu).at(k));
	}

	h_cluster_id_ext->Fill(cluster_id_v->at(i_clu));
	h_parent_cluster_id_ext->Fill(parent_cluster_id_v->at(i_clu));
	h_time_slice_ext->Fill(time_slice_v->at(i_clu));
	
	h_q_ext->Fill(q_v->at(i_clu));
	h_uq_ext->Fill(uq_v->at(i_clu));
	h_vq_ext->Fill(vq_v->at(i_clu));
	h_wq_ext->Fill(wq_v->at(i_clu));
	h_udq_ext->Fill(udq_v->at(i_clu));
	h_vdq_ext->Fill(vdq_v->at(i_clu));
        h_wdq_ext->Fill(wdq_v->at(i_clu));
        h_nwire_u_ext->Fill(nwire_u_v->at(i_clu));
	h_nwire_v_ext->Fill(nwire_v_v->at(i_clu));
	h_nwire_w_ext->Fill(nwire_w_v->at(i_clu));
	for(int k=0; k< wire_index_u_vv->at(i_clu).size(); k++)	h_wire_index_u_ext->Fill(wire_index_u_vv->at(i_clu).at(k)); 
	for(int k=0; k< wire_index_v_vv->at(i_clu).size(); k++) h_wire_index_v_ext->Fill(wire_index_v_vv->at(i_clu).at(k));    
	for(int k=0; k< wire_index_w_vv->at(i_clu).size(); k++)        h_wire_index_w_ext->Fill(wire_index_w_vv->at(i_clu).at(k));    
	for(int k=0; k< wire_charge_u_vv->at(i_clu).size(); k++)        h_wire_charge_u_ext->Fill(wire_charge_u_vv->at(i_clu).at(k));    
	for(int k=0; k< wire_charge_v_vv->at(i_clu).size(); k++)        h_wire_charge_v_ext->Fill(wire_charge_v_vv->at(i_clu).at(k));    
	for(int k=0; k< wire_charge_w_vv->at(i_clu).size(); k++)	h_wire_charge_w_ext->Fill(wire_charge_w_vv->at(i_clu).at(k)); 
	for(int k=0; k< wire_charge_err_u_vv->at(i_clu).size(); k++)  h_wire_charge_err_u_ext->Fill(wire_charge_err_u_vv->at(i_clu).at(k)); 
	for(int k=0; k< wire_charge_err_v_vv->at(i_clu).size(); k++)   h_wire_charge_err_v_ext->Fill(wire_charge_err_v_vv->at(i_clu).at(k)); 
	for(int k=0; k< wire_charge_err_w_vv->at(i_clu).size(); k++)	h_wire_charge_err_w_ext->Fill(wire_charge_err_w_vv->at(i_clu).at(k));
      }
	
    }
  
    h_extent_x_ext->Fill(extent_x_max-extent_x_min);
    h_extent_y_ext->Fill(extent_y_max-extent_y_min);
    h2_extent_xy_ext->Fill(extent_x_max-extent_x_min, extent_y_max-extent_y_min);
  }  



  
  fnew->Write();
}





void study_9(){

  TFile *fnew = new TFile ("out_study.root","recreate");  

  tree_ext_TC->SetBranchAddress("cluster_id",&cluster_id_v);
  tree_ext_TC->SetBranchAddress("parent_cluster_id",&parent_cluster_id_v);
  tree_ext_TC->SetBranchAddress("time_slice",&time_slice_v);
  tree_ext_TC->SetBranchAddress("q",&q_v);
  tree_ext_TC->SetBranchAddress("uq",&uq_v);
  tree_ext_TC->SetBranchAddress("vq",&vq_v);
  tree_ext_TC->SetBranchAddress("wq",&wq_v);
  tree_ext_TC->SetBranchAddress("udq",&udq_v);
  tree_ext_TC->SetBranchAddress("vdq",&vdq_v);
  tree_ext_TC->SetBranchAddress("wdq",&wdq_v);
  tree_ext_TC->SetBranchAddress("nwire_u",&nwire_u_v);
  tree_ext_TC->SetBranchAddress("nwire_v",&nwire_v_v);
  tree_ext_TC->SetBranchAddress("nwire_w",&nwire_w_v);
  tree_ext_TC->SetBranchAddress("flag_u",&flag_u_v);
  tree_ext_TC->SetBranchAddress("flag_v",&flag_v_v);
  tree_ext_TC->SetBranchAddress("flag_w",&flag_w_v);
  tree_ext_TC->SetBranchAddress("wire_index_u",&wire_index_u_vv);
  tree_ext_TC->SetBranchAddress("wire_index_v",&wire_index_v_vv);
  tree_ext_TC->SetBranchAddress("wire_index_w",&wire_index_w_vv);
  tree_ext_TC->SetBranchAddress("wire_charge_u",&wire_charge_u_vv);
  tree_ext_TC->SetBranchAddress("wire_charge_v",&wire_charge_v_vv);
  tree_ext_TC->SetBranchAddress("wire_charge_w",&wire_charge_w_vv);
  tree_ext_TC->SetBranchAddress("wire_charge_err_u",&wire_charge_err_u_vv);
  tree_ext_TC->SetBranchAddress("wire_charge_err_v",&wire_charge_err_v_vv);
  tree_ext_TC->SetBranchAddress("wire_charge_err_w",&wire_charge_err_w_vv);

  tree_nnbar_TC->SetBranchAddress("cluster_id",&cluster_id_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("parent_cluster_id",&parent_cluster_id_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("time_slice",&time_slice_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("q",&q_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("uq",&uq_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("vq",&vq_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("wq",&wq_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("udq",&udq_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("vdq",&vdq_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("wdq",&wdq_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("nwire_u",&nwire_u_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("nwire_v",&nwire_v_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("nwire_w",&nwire_w_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("flag_u",&flag_u_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("flag_v",&flag_v_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("flag_w",&flag_w_v_nnbar);
  tree_nnbar_TC->SetBranchAddress("wire_index_u",&wire_index_u_vv_nnbar);
  tree_nnbar_TC->SetBranchAddress("wire_index_v",&wire_index_v_vv_nnbar);
  tree_nnbar_TC->SetBranchAddress("wire_index_w",&wire_index_w_vv_nnbar);
  tree_nnbar_TC->SetBranchAddress("wire_charge_u",&wire_charge_u_vv_nnbar);


  tree_nnbar_TC->SetBranchAddress("wire_charge_v",&wire_charge_v_vv_nnbar);
  tree_nnbar_TC->SetBranchAddress("wire_charge_w",&wire_charge_w_vv_nnbar);
  tree_nnbar_TC->SetBranchAddress("wire_charge_err_u",&wire_charge_err_u_vv_nnbar);

  tree_nnbar_TC->SetBranchAddress("wire_charge_err_v",&wire_charge_err_v_vv_nnbar);
  tree_nnbar_TC->SetBranchAddress("wire_charge_err_w",&wire_charge_err_w_vv_nnbar);
  
  /*
  */
  TH1F *h_cluster_id = new TH1F("h_cluster_id","h_cluster_id",240,0,240);
  TH1F *h_parent_cluster_id = new TH1F("h_parent_cluster_id","h_parent_cluster_id",240,0,240);
  TH1F *h_time_slice = new TH1F("h_time_slice","h_time_slice",40,0,2400);
  TH1F *h_q = new TH1F("h_q","h_q",50,0,30000);
  TH1F *h_uq = new TH1F("h_uq","h_uq",50,0,100000);
  TH1F *h_vq = new TH1F("h_vq","h_vq",50,0,100000);
  TH1F *h_wq = new TH1F("h_wq","h_wq",50,0,100000);
  TH1F *h_udq = new TH1F("h_udq","h_udq",50,0,10000);
  TH1F *h_vdq = new TH1F("h_vdq","h_vdq",50,0,10000);
  TH1F *h_wdq = new TH1F("h_wdq","h_wdq",50,0,2500);
  TH1F *h_nwire_u = new TH1F("h_nwire_u","h_nwire_u",50,0,50);
  TH1F *h_nwire_v = new TH1F("h_nwire_v","h_nwire_v",50,0,50);
  TH1F *h_nwire_w = new TH1F("h_nwire_w","h_nwire_w",50,0,50);
  TH1F *h_wire_index_u = new TH1F("h2_wire_index_u","h2_wire_index_u",240,0,2400);
  TH1F *h_wire_index_v	= new TH1F("h2_wire_index_v","h2_wire_index_v",240,0,2400);
  TH1F *h_wire_index_w  = new TH1F("h2_wire_index_w","h2_wire_index_w",350,0,3500);

  TH1F *h_wire_charge_u	= new TH1F("h2_wire_charge_u","h2_wire_charge_u",50,0,50000);
  TH1F *h_wire_charge_v  = new TH1F("h2_wire_charge_v","h2_wire_charge_v",50,0,50000);
  TH1F *h_wire_charge_w  = new TH1F("h2_wire_charge_w","h2_wire_charge_w",50,0,50000);
  TH1F *h_wire_charge_err_u	= new TH1F("h2_wire_charge_err_u","h2_wire_charge_err_u",50,0,2500);
  TH1F *h_wire_charge_err_v  = new TH1F("h2_wire_charge_err_v","h2_wire_charge_err_v",50,0,4000);
  TH1F *h_wire_charge_err_w  = new TH1F("h2_wire_charge_err_w","h2_wire_charge_err_w",20,0,400);
  
  int ext_entries = tree_ext_TC->GetEntries();
  std::cout << "ext_entries: " << ext_entries << std::endl; 
  for (int i=0; i<ext_entries; i++){
    tree_ext_TC->GetEntry(i);
    //std::cout<< i<<"-th event" << std::endl;
    for (int j=0; j < cluster_id_v->size(); j++)     h_cluster_id->Fill(cluster_id_v->at(j));
    for (int j=0; j < parent_cluster_id_v->size(); j++)    h_parent_cluster_id->Fill(parent_cluster_id_v->at(j));
    for (int j=0; j < time_slice_v->size(); j++)      h_time_slice->Fill(time_slice_v->at(j));
    for (int j=0; j < q_v->size(); j++)      h_q->Fill(q_v->at(j));
    for (int j=0; j < uq_v->size(); j++)      h_uq->Fill(uq_v->at(j));
    for (int j=0; j < vq_v->size(); j++)      h_vq->Fill(vq_v->at(j));
    for (int j=0; j < wq_v->size(); j++)      h_wq->Fill(wq_v->at(j));
    for (int j=0; j < udq_v->size(); j++)      h_udq->Fill(udq_v->at(j));
    for (int j=0; j < vdq_v->size(); j++)      h_vdq->Fill(vdq_v->at(j));
    for (int j=0; j < wdq_v->size(); j++)      h_wdq->Fill(wdq_v->at(j));
    for (int j=0; j < nwire_u_v->size(); j++)      h_nwire_u->Fill(nwire_u_v->at(j));
    for (int j=0; j < nwire_v_v->size(); j++)      h_nwire_v->Fill(nwire_v_v->at(j));
    for (int j=0; j < nwire_w_v->size(); j++)      h_nwire_w->Fill(nwire_w_v->at(j));
    
    for (int j=0; j < wire_index_u_vv->size(); j++){
      for(int k=0; k< wire_index_u_vv->at(j).size(); k++)	h_wire_index_u->Fill(wire_index_u_vv->at(j).at(k)); }
    for (int j=0; j < wire_index_v_vv->size(); j++){
      for(int k=0; k< wire_index_v_vv->at(j).size(); k++) h_wire_index_v->Fill(wire_index_v_vv->at(j).at(k));    }
    for (int j=0; j < wire_index_w_vv->size(); j++){
      for(int k=0; k< wire_index_w_vv->at(j).size(); k++)        h_wire_index_w->Fill(wire_index_w_vv->at(j).at(k));    }
    for (int j=0; j < wire_charge_u_vv->size(); j++){
      for(int k=0; k< wire_charge_u_vv->at(j).size(); k++)        h_wire_charge_u->Fill(wire_charge_u_vv->at(j).at(k));    }
    for (int j=0; j < wire_charge_v_vv->size(); j++){
      for(int k=0; k< wire_charge_v_vv->at(j).size(); k++)        h_wire_charge_v->Fill(wire_charge_v_vv->at(j).at(k));    }
    for (int j=0; j < wire_charge_w_vv->size(); j++){
      for(int k=0; k< wire_charge_w_vv->at(j).size(); k++)	h_wire_charge_w->Fill(wire_charge_w_vv->at(j).at(k)); }
    for (int j=0; j < wire_charge_err_u_vv->size(); j++){
      for(int k=0; k< wire_charge_err_u_vv->at(j).size(); k++)  h_wire_charge_err_u->Fill(wire_charge_err_u_vv->at(j).at(k)); }
    for (int j=0; j < wire_charge_err_v_vv->size(); j++){
      for(int k=0; k< wire_charge_err_v_vv->at(j).size(); k++)   h_wire_charge_err_v->Fill(wire_charge_err_v_vv->at(j).at(k)); }
    for (int j=0; j < wire_charge_err_w_vv->size(); j++){
      for(int k=0; k< wire_charge_err_w_vv->at(j).size(); k++)	h_wire_charge_err_w->Fill(wire_charge_err_w_vv->at(j).at(k));  }
  }

  TH1F *h_cluster_id_nnbar = new TH1F("h_cluster_id_nnbar","h_cluster_id_nnbar",240,0,240);
  TH1F *h_parent_cluster_id_nnbar = new TH1F("h_parent_cluster_id_nnbar","h_parent_cluster_id_nnbar",240,0,240);
  TH1F *h_time_slice_nnbar = new TH1F("h_time_slice_nnbar","h_time_slice_nnbar",40,0,2400);
  TH1F *h_q_nnbar = new TH1F("h_q_nnbar","h_q_nnbar",50,0,30000);
  TH1F *h_uq_nnbar = new TH1F("h_uq_nnbar","h_uq_nnbar",50,0,100000);
  TH1F *h_vq_nnbar = new TH1F("h_vq_nnbar","h_vq_nnbar",50,0,100000);
  TH1F *h_wq_nnbar = new TH1F("h_wq_nnbar","h_wq_nnbar",50,0,100000);
  TH1F *h_udq_nnbar = new TH1F("h_udq_nnbar","h_udq_nnbar",50,0,10000);
  TH1F *h_vdq_nnbar = new TH1F("h_vdq_nnbar","h_vdq_nnbar",50,0,10000);
  TH1F *h_wdq_nnbar = new TH1F("h_wdq_nnbar","h_wdq_nnbar",50,0,2500);
  TH1F *h_nwire_u_nnbar = new TH1F("h_nwire_u_nnbar","h_nwire_u_nnbar",50,0,50);
  TH1F *h_nwire_v_nnbar = new TH1F("h_nwire_v_nnbar","h_nwire_v_nnbar",50,0,50);
  TH1F *h_nwire_w_nnbar = new TH1F("h_nwire_w_nnbar","h_nwire_w_nnbar",50,0,50);
  TH1F *h_wire_index_u_nnbar = new TH1F("h2_wire_index_u_nnbar","h2_wire_index_u_nnbar",240,0,2400);
  TH1F *h_wire_index_v_nnbar	= new TH1F("h2_wire_index_v_nnbar","h2_wire_index_v_nnbar",240,0,2400);
  TH1F *h_wire_index_w_nnbar  = new TH1F("h2_wire_index_w_nnbar","h2_wire_index_w_nnbar",350,0,3500);

  TH1F *h_wire_charge_u_nnbar	= new TH1F("h2_wire_charge_u_nnbar","h2_wire_charge_u_nnbar",50,0,50000);
  TH1F *h_wire_charge_v_nnbar  = new TH1F("h2_wire_charge_v_nnbar","h2_wire_charge_v_nnbar",50,0,50000);
  TH1F *h_wire_charge_w_nnbar  = new TH1F("h2_wire_charge_w_nnbar","h2_wire_charge_w_nnbar",50,0,50000);
  TH1F *h_wire_charge_err_u_nnbar	= new TH1F("h2_wire_charge_err_u_nnbar","h2_wire_charge_err_u_nnbar",50,0,2500);
  TH1F *h_wire_charge_err_v_nnbar  = new TH1F("h2_wire_charge_err_v_nnbar","h2_wire_charge_err_v_nnbar",50,0,4000);
  TH1F *h_wire_charge_err_w_nnbar  = new TH1F("h2_wire_charge_err_w_nnbar","h2_wire_charge_err_w_nnbar",20,0,400);
  
  int nnbar_entries = tree_nnbar_TC->GetEntries();
  std::cout << "nnbar_entries: " << nnbar_entries << std::endl;
  for (int i=0; i<nnbar_entries; i++){
    tree_nnbar_TC->GetEntry(i);
    //std::cout<< i<<"-th event" << std::endl;
    for (int j=0; j < cluster_id_v_nnbar->size(); j++)     h_cluster_id_nnbar->Fill(cluster_id_v_nnbar->at(j));
    for (int j=0; j < parent_cluster_id_v_nnbar->size(); j++)    h_parent_cluster_id_nnbar->Fill(parent_cluster_id_v_nnbar->at(j));
    for (int j=0; j < time_slice_v_nnbar->size(); j++)      h_time_slice_nnbar->Fill(time_slice_v_nnbar->at(j));
    for (int j=0; j < q_v_nnbar->size(); j++)      h_q_nnbar->Fill(q_v_nnbar->at(j));
    for (int j=0; j < uq_v_nnbar->size(); j++)      h_uq_nnbar->Fill(uq_v_nnbar->at(j));
    for (int j=0; j < vq_v_nnbar->size(); j++)      h_vq_nnbar->Fill(vq_v_nnbar->at(j));
    for (int j=0; j < wq_v_nnbar->size(); j++)      h_wq_nnbar->Fill(wq_v_nnbar->at(j));
    for (int j=0; j < udq_v_nnbar->size(); j++)      h_udq_nnbar->Fill(udq_v_nnbar->at(j));
    for (int j=0; j < vdq_v_nnbar->size(); j++)      h_vdq_nnbar->Fill(vdq_v_nnbar->at(j));
    for (int j=0; j < wdq_v_nnbar->size(); j++)      h_wdq_nnbar->Fill(wdq_v_nnbar->at(j));
    for (int j=0; j < nwire_u_v_nnbar->size(); j++)      h_nwire_u_nnbar->Fill(nwire_u_v_nnbar->at(j));
    for (int j=0; j < nwire_v_v_nnbar->size(); j++)      h_nwire_v_nnbar->Fill(nwire_v_v_nnbar->at(j));
    for (int j=0; j < nwire_w_v_nnbar->size(); j++)      h_nwire_w_nnbar->Fill(nwire_w_v_nnbar->at(j));
    
    for (int j=0; j < wire_index_u_vv_nnbar->size(); j++){
      for(int k=0; k< wire_index_u_vv_nnbar->at(j).size(); k++)	h_wire_index_u_nnbar->Fill(wire_index_u_vv_nnbar->at(j).at(k)); }
    for (int j=0; j < wire_index_v_vv_nnbar->size(); j++){
      for(int k=0; k< wire_index_v_vv_nnbar->at(j).size(); k++) h_wire_index_v_nnbar->Fill(wire_index_v_vv_nnbar->at(j).at(k));    }
    for (int j=0; j < wire_index_w_vv_nnbar->size(); j++){
      for(int k=0; k< wire_index_w_vv_nnbar->at(j).size(); k++)        h_wire_index_w_nnbar->Fill(wire_index_w_vv_nnbar->at(j).at(k));    }
    for (int j=0; j < wire_charge_u_vv_nnbar->size(); j++){
      for(int k=0; k< wire_charge_u_vv_nnbar->at(j).size(); k++)        h_wire_charge_u_nnbar->Fill(wire_charge_u_vv_nnbar->at(j).at(k));    }
    for (int j=0; j < wire_charge_v_vv_nnbar->size(); j++){
      for(int k=0; k< wire_charge_v_vv_nnbar->at(j).size(); k++)        h_wire_charge_v_nnbar->Fill(wire_charge_v_vv_nnbar->at(j).at(k));    }
    for (int j=0; j < wire_charge_w_vv_nnbar->size(); j++){
      for(int k=0; k< wire_charge_w_vv_nnbar->at(j).size(); k++)	h_wire_charge_w_nnbar->Fill(wire_charge_w_vv_nnbar->at(j).at(k)); }
    for (int j=0; j < wire_charge_err_u_vv_nnbar->size(); j++){
      for(int k=0; k< wire_charge_err_u_vv_nnbar->at(j).size(); k++)  h_wire_charge_err_u_nnbar->Fill(wire_charge_err_u_vv_nnbar->at(j).at(k)); }
    for (int j=0; j < wire_charge_err_v_vv_nnbar->size(); j++){
      for(int k=0; k< wire_charge_err_v_vv_nnbar->at(j).size(); k++)   h_wire_charge_err_v_nnbar->Fill(wire_charge_err_v_vv_nnbar->at(j).at(k)); }
    for (int j=0; j < wire_charge_err_w_vv_nnbar->size(); j++){
      for(int k=0; k< wire_charge_err_w_vv_nnbar->at(j).size(); k++)	h_wire_charge_err_w_nnbar->Fill(wire_charge_err_w_vv_nnbar->at(j).at(k));  }
  }


  h_cluster_id_nnbar->SetLineColor(1);
  h_parent_cluster_id_nnbar->SetLineColor(1);
  h_time_slice_nnbar->SetLineColor(1);
  h_q_nnbar->SetLineColor(1);
  h_uq_nnbar->SetLineColor(1);
  h_vq_nnbar->SetLineColor(1);
  h_wq_nnbar->SetLineColor(1);
  h_udq_nnbar->SetLineColor(1);
  h_vdq_nnbar->SetLineColor(1);
  h_wdq_nnbar->SetLineColor(1);
  h_nwire_u_nnbar->SetLineColor(1);
  h_nwire_v_nnbar->SetLineColor(1);
  h_nwire_w_nnbar->SetLineColor(1);
  h_wire_index_u_nnbar->SetLineColor(1);
  h_wire_index_v_nnbar->SetLineColor(1);
  h_wire_index_w_nnbar->SetLineColor(1);
  h_wire_charge_u_nnbar->SetLineColor(1);
  h_wire_charge_v_nnbar->SetLineColor(1);
  h_wire_charge_w_nnbar->SetLineColor(1);
  h_wire_charge_err_u_nnbar->SetLineColor(1);
  h_wire_charge_err_v_nnbar->SetLineColor(1);
  h_wire_charge_err_w_nnbar->SetLineColor(1);

  
  TCanvas *c_cluster_id = new TCanvas("c_cluster_id","c_cluster_id",800,600);
  h_cluster_id_nnbar->Draw();
  h_cluster_id->Draw("same");

  
  TCanvas *c_cluster_id_ratio = new TCanvas("c_cluster_id_ratio","c_cluster_id_ratio",800,100);
  TH1D *h_cluster_id_ratio = (TH1D*)h_cluster_id_nnbar->Clone();
  h_cluster_id_ratio->Divide(h_cluster_id);
  h_cluster_id_ratio->Draw();
 
  
  TCanvas *c_parent_cluster_id = new TCanvas("c_parent_cluster_id","c_parent_cluster_id",800,600);
  h_parent_cluster_id_nnbar->Draw();
  h_parent_cluster_id->Draw("same");
  TCanvas *c_time_slice = new TCanvas("c_time_slice","c_time_slice",800,600);
  h_time_slice_nnbar->Draw();
  h_time_slice->Draw("same");
  TCanvas *c_q = new TCanvas("c_q","c_q",800,600);
  h_q_nnbar->Draw();
  h_q->Draw("same");
  TCanvas *c_uq = new TCanvas("c_uq","c_uq",800,600);
  h_uq_nnbar->Draw();
  h_uq->Draw("same");
  TCanvas *c_vq = new TCanvas("c_vq","c_vq",800,600);
  h_vq_nnbar->Draw();
  h_vq->Draw("same");
  TCanvas *c_wq = new TCanvas("c_wq","c_wq",800,600);
  h_wq_nnbar->Draw();
  h_wq->Draw("same");
  TCanvas *c_udq = new TCanvas("c_udq","c_udq",800,600);
  h_udq_nnbar->Draw();
  h_udq->Draw("same");
  TCanvas *c_vdq = new TCanvas("c_vdq","c_vdq",800,600);
  h_vdq_nnbar->Draw();
  h_vdq->Draw("same");
  TCanvas *c_wdq = new TCanvas("c_wdq","c_wdq",800,600);
  h_wdq_nnbar->Draw();
  h_wdq->Draw("same");
  TCanvas *c_nwire_u = new TCanvas("c_nwire_u","c_nwire_u",800,600);
  h_nwire_u_nnbar->Draw();
  h_nwire_u->Draw("same");
  TCanvas *c_nwire_v = new TCanvas("c_nwire_v","c_nwire_v",800,600);
  h_nwire_v_nnbar->Draw();
  h_nwire_v->Draw("same");
  TCanvas *c_nwire_w = new TCanvas("c_nwire_w","c_nwire_w",800,600);
  h_nwire_w_nnbar->Draw();
  h_nwire_w->Draw("same");

  TCanvas *c_wire_index_u = new TCanvas("c_wire_index_u","c_wire_index_u",800,600);
  h_wire_index_u_nnbar->Draw();
  h_wire_index_u->Draw("same");
  TCanvas *c_wire_index_v = new TCanvas("c_wire_index_v","c_wire_index_v",800,600);
  h_wire_index_v_nnbar->Draw();
  h_wire_index_v->Draw("same");
  TCanvas *c_wire_index_w = new TCanvas("c_wire_index_w","c_wire_index_w",800,600);
  h_wire_index_w_nnbar->Draw();
  h_wire_index_w->Draw("same");

   TCanvas *c_wire_charge_u = new TCanvas("c_wire_charge_u","c_wire_charge_u",800,600);
  h_wire_charge_u_nnbar->Draw();
  h_wire_charge_u->Draw("same");
  TCanvas *c_wire_charge_v = new TCanvas("c_wire_charge_v","c_wire_charge_v",800,600);
  h_wire_charge_v_nnbar->Draw();
  h_wire_charge_v->Draw("same");
  TCanvas *c_wire_charge_w = new TCanvas("c_wire_charge_w","c_wire_charge_w",800,600);
  h_wire_charge_w_nnbar->Draw();
  h_wire_charge_w->Draw("same");

   TCanvas *c_wire_charge_err_u = new TCanvas("c_wire_charge_err_u","c_wire_charge_err_u",800,600);
  h_wire_charge_err_u_nnbar->Draw();
  h_wire_charge_err_u->Draw("same");
  TCanvas *c_wire_charge_err_v = new TCanvas("c_wire_charge_err_v","c_wire_charge_err_v",800,600);
  h_wire_charge_err_v_nnbar->Draw();
  h_wire_charge_err_v->Draw("same");
  TCanvas *c_wire_charge_err_w = new TCanvas("c_wire_charge_err_w","c_wire_charge_err_w",800,600);
  h_wire_charge_err_w_nnbar->Draw();
  h_wire_charge_err_w->Draw("same");


  TCanvas *c_time_slice_ratio = new TCanvas("c_time_slice_ratio","c_time_slice_ratio",800,200);
  TH1D *h_time_slice_ratio = (TH1D*)h_time_slice_nnbar->Clone();
  h_time_slice_ratio->Divide(h_time_slice);
  h_time_slice_ratio->GetYaxis()->SetRangeUser(0.8,1.5);
  h_time_slice_ratio->Draw();
  
  TCanvas *c_q_ratio = new TCanvas("c_q_ratio","c_q_ratio",800,200);
  TH1D *h_q_ratio = (TH1D*)h_q_nnbar->Clone();
  h_q_ratio->Divide(h_q);
  h_q_ratio->GetYaxis()->SetRangeUser(0.8,1.5);
  h_q_ratio->Draw();
    TCanvas *c_uq_ratio = new TCanvas("c_uq_ratio","c_uq_ratio",800,200);
  TH1D *h_uq_ratio = (TH1D*)h_uq_nnbar->Clone();
  h_uq_ratio->Divide(h_uq);
  h_uq_ratio->GetYaxis()->SetRangeUser(0.8,1.5);
  h_uq_ratio->Draw();
    TCanvas *c_vq_ratio = new TCanvas("c_vq_ratio","c_vq_ratio",800,200);
  TH1D *h_vq_ratio = (TH1D*)h_vq_nnbar->Clone();
  h_vq_ratio->Divide(h_vq);
  h_vq_ratio->GetYaxis()->SetRangeUser(0.8,1.5);
  h_vq_ratio->Draw();
    TCanvas *c_wq_ratio = new TCanvas("c_wq_ratio","c_wq_ratio",800,200);
  TH1D *h_wq_ratio = (TH1D*)h_wq_nnbar->Clone();
  h_wq_ratio->Divide(h_wq);
  h_wq_ratio->GetYaxis()->SetRangeUser(0.8,1.5);
  h_wq_ratio->Draw();
    TCanvas *c_udq_ratio = new TCanvas("c_udq_ratio","c_udq_ratio",800,200);
  TH1D *h_udq_ratio = (TH1D*)h_udq_nnbar->Clone();
  h_udq_ratio->Divide(h_udq);
  h_udq_ratio->GetYaxis()->SetRangeUser(0.8,1.5);
  h_udq_ratio->Draw();
    TCanvas *c_vdq_ratio = new TCanvas("c_vdq_ratio","c_vdq_ratio",800,200);
  TH1D *h_vdq_ratio = (TH1D*)h_vdq_nnbar->Clone();
  h_vdq_ratio->Divide(h_vdq);
  h_vdq_ratio->GetYaxis()->SetRangeUser(0.8,1.5);
  h_vdq_ratio->Draw();
    TCanvas *c_wdq_ratio = new TCanvas("c_wdq_ratio","c_wdq_ratio",800,200);
  TH1D *h_wdq_ratio = (TH1D*)h_wdq_nnbar->Clone();
  h_wdq_ratio->Divide(h_wdq);
  h_wdq_ratio->GetYaxis()->SetRangeUser(0.8,1.5);
  h_wdq_ratio->Draw();
    TCanvas *c_nwire_u_ratio = new TCanvas("c_nwire_u_ratio","c_nwire_u_ratio",800,200);
  TH1D *h_nwire_u_ratio = (TH1D*)h_nwire_u_nnbar->Clone();
  h_nwire_u_ratio->Divide(h_nwire_u);
  h_nwire_u_ratio->GetYaxis()->SetRangeUser(0.8,1.5);
  h_nwire_u_ratio->Draw();
    TCanvas *c_nwire_v_ratio = new TCanvas("c_nwire_v_ratio","c_nwire_v_ratio",800,200);
  TH1D *h_nwire_v_ratio = (TH1D*)h_nwire_v_nnbar->Clone();
  h_nwire_v_ratio->Divide(h_nwire_v);
  h_nwire_v_ratio->GetYaxis()->SetRangeUser(0.8,1.5);
  h_nwire_v_ratio->Draw();
    TCanvas *c_nwire_w_ratio = new TCanvas("c_nwire_w_ratio","c_nwire_w_ratio",800,200);
  TH1D *h_nwire_w_ratio = (TH1D*)h_nwire_w_nnbar->Clone();
  h_nwire_w_ratio->Divide(h_nwire_w);
  h_nwire_w_ratio->GetYaxis()->SetRangeUser(0.8,1.5);
  h_nwire_w_ratio->Draw();
    TCanvas *c_wire_index_u_ratio = new TCanvas("c_wire_index_u_ratio","c_wire_index_u_ratio",800,200);
  TH1D *h_wire_index_u_ratio = (TH1D*)h_wire_index_u_nnbar->Clone();
  h_wire_index_u_ratio->Divide(h_wire_index_u);
  h_wire_index_u_ratio->GetYaxis()->SetRangeUser(0.8,1.5);
  h_wire_index_u_ratio->Draw();
    TCanvas *c_wire_index_v_ratio = new TCanvas("c_wire_index_v_ratio","c_wire_index_v_ratio",800,200);
  TH1D *h_wire_index_v_ratio = (TH1D*)h_wire_index_v_nnbar->Clone();
  h_wire_index_v_ratio->Divide(h_wire_index_v);
  h_wire_index_v_ratio->GetYaxis()->SetRangeUser(0.8,1.5);
  h_wire_index_v_ratio->Draw();

     TCanvas *c_wire_index_w_ratio = new TCanvas("c_wire_index_w_ratio","c_wire_index_w_ratio",800,200);
  TH1D *h_wire_index_w_ratio = (TH1D*)h_wire_index_w_nnbar->Clone();
  h_wire_index_w_ratio->Divide(h_wire_index_w);
  h_wire_index_w_ratio->GetYaxis()->SetRangeUser(0.8,1.5);
  h_wire_index_w_ratio->Draw();

     TCanvas *c_wire_charge_u_ratio = new TCanvas("c_wire_charge_u_ratio","c_wire_charge_u_ratio",800,200);
  TH1D *h_wire_charge_u_ratio = (TH1D*)h_wire_charge_u_nnbar->Clone();
  h_wire_charge_u_ratio->Divide(h_wire_charge_u);
  h_wire_charge_u_ratio->GetYaxis()->SetRangeUser(0.8,1.5);
  h_wire_charge_u_ratio->Draw();

     TCanvas *c_wire_charge_v_ratio = new TCanvas("c_wire_charge_v_ratio","c_wire_charge_v_ratio",800,200);
  TH1D *h_wire_charge_v_ratio = (TH1D*)h_wire_charge_v_nnbar->Clone();
  h_wire_charge_v_ratio->Divide(h_wire_charge_v);
  h_wire_charge_v_ratio->GetYaxis()->SetRangeUser(0.8,1.5);
  h_wire_charge_v_ratio->Draw();

     TCanvas *c_wire_charge_w_ratio = new TCanvas("c_wire_charge_w_ratio","c_wire_charge_w_ratio",800,200);
  TH1D *h_wire_charge_w_ratio = (TH1D*)h_wire_charge_w_nnbar->Clone();
  h_wire_charge_w_ratio->Divide(h_wire_charge_w);
  h_wire_charge_w_ratio->GetYaxis()->SetRangeUser(0.8,1.5);
  h_wire_charge_w_ratio->Draw();

     TCanvas *c_wire_charge_err_u_ratio = new TCanvas("c_wire_charge_err_u_ratio","c_wire_charge_err_u_ratio",800,200);
  TH1D *h_wire_charge_err_u_ratio = (TH1D*)h_wire_charge_err_u_nnbar->Clone();
  h_wire_charge_err_u_ratio->Divide(h_wire_charge_err_u);
  h_wire_charge_err_u_ratio->GetYaxis()->SetRangeUser(0.8,1.5);
  h_wire_charge_err_u_ratio->Draw();

   TCanvas *c_wire_charge_err_v_ratio = new TCanvas("c_wire_charge_err_v_ratio","c_wire_charge_err_v_ratio",800,200);
  TH1D *h_wire_charge_err_v_ratio = (TH1D*)h_wire_charge_err_v_nnbar->Clone();
  h_wire_charge_err_v_ratio->Divide(h_wire_charge_err_v);
  h_wire_charge_err_v_ratio->GetYaxis()->SetRangeUser(0.8,1.5);
  h_wire_charge_err_v_ratio->Draw();

   TCanvas *c_wire_charge_err_w_ratio = new TCanvas("c_wire_charge_err_w_ratio","c_wire_charge_err_w_ratio",800,200);
  TH1D *h_wire_charge_err_w_ratio = (TH1D*)h_wire_charge_err_w_nnbar->Clone();
  h_wire_charge_err_w_ratio->Divide(h_wire_charge_err_w);
  h_wire_charge_err_w_ratio->GetYaxis()->SetRangeUser(0.8,1.5);
  h_wire_charge_err_w_ratio->Draw();







  
  fnew->Write();
  
}

    /*
    std::cout << "cluster length :" << cluster_id_v->size() << ", value : " << cluster_id_v->at(0)<< std::endl;
    for (int clu_idx=0; clu_idx < cluster_id_v->size(); clu_idx++){
      if (cluster_id_v->at(clu_idx) ==1){
    std::cout << "parent_cluster length : " << parent_cluster_id_v->size()<< ", value : " << cluster_id_v->at(0) << std::endl;
    std::cout << "q length :" << q_v->size()<< ", value : " << cluster_id_v->at(0) << std::endl;
    std::cout << "uq length : " << uq_v->size() << ", value : " << cluster_id_v->at(0)<<	std::endl;
    std::cout << "vq length : " << vq_v->size() << ", value : " << cluster_id_v->at(0)<< std::endl;
    std::cout << "wq length : "	<< wq_v->size() << ", value : " << cluster_id_v->at(0)<< std::endl;
    std::cout << "udq length : " << udq_v->size() << ", value : " << udq_v->at(0)<< std::endl;
    std::cout << "vdq length : " << vdq_v->size() << ", value : " << vdq_v->at(0)<< std::endl;
    std::cout << "wdq length : " << wdq_v->size() << ", value : " << wdq_v->at(0)<< std::endl;
    std::cout << "nwire_u length : " << nwire_u_v->size() << ", value : " << nwire_u_v->at(0)<< std::endl;
    std::cout << "nwire_v length : " << nwire_v_v->size() << ", value : " << nwire_v_v->at(0)<< std::endl;
    std::cout << "nwire_w length : " << nwire_w_v->size() << ", value : " << nwire_w_v->at(0)<< std::endl;
    std::cout << "flag_u length : " << flag_u_v->size() << ", value : " << flag_u_v->at(0)<< std::endl;
    std::cout << "flag_v length : " << flag_v_v->size() << ", value : " << flag_v_v->at(0)<< std::endl;
    std::cout << "flag_w length : " << flag_w_v->size() << ", value : " << flag_w_v->at(0)<< std::endl;
    std::cout << "wire_index_u length :" << wire_index_u_vv->size() << std::endl;
    for (int j=0; j<wire_index_u_vv->at(0).size(); j++){
      std::cout << j<<"-th wire_single : " << wire_index_u_vv->at(0).at(j) << std::endl; 
    }
    std::cout << "wire_index_v length :" << wire_index_v_vv->size() << std::endl;
    for	(int j=0; j<wire_index_v_vv->at(0).size(); j++){
      std::cout	<< j<<"-th wire_single : " << wire_index_v_vv->at(0).at(j) << std::endl;
    }
    std::cout << "wire_index_w length :" << wire_index_w_vv->size() << std::endl;
    for	(int j=0; j<wire_index_w_vv->at(0).size(); j++){
      std::cout	<< j<<"-th wire_single : " << wire_index_w_vv->at(0).at(j) << std::endl;
    }
    std::cout << "wire_charge_u length :" << wire_charge_u_vv->size() << std::endl;
    std::cout << "wire_charge_v length :" << wire_charge_v_vv->size() << std::endl;
    std::cout << "wire_charge_w length :" << wire_charge_w_vv->size() << std::endl;
    std::cout << "wire_charge_err_u length :" << wire_charge_err_u_vv->size() << std::endl;
    std::cout << "wire_charge_err_v length :" << wire_charge_err_v_vv->size() << std::endl;
    std::cout << "wire_charge_err_w length :" << wire_charge_err_w_vv->size() << std::endl;
    }
    }
    //for (size j=0; j<cluster_id_v->size(); j++){
    //  std::cout << "cluster id : " << cluster_id_v[i] << std::endl;
    //}
    */
