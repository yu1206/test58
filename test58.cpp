#include "DataAug.h"

extern int readDir(char *dirName, vector<string> &filesName);

void initBatchSampler(vector<BatchSampler> &  batch_samplers)
{
	BatchSampler sampler;
	memset(&sampler, 0, sizeof(BatchSampler));
	sampler.min_scale = 1;
	sampler.max_scale = 1.0;
	sampler.min_aspect_ratio = 1;
	sampler.max_aspect_ratio = 1;
	sampler.has_min_jaccard_overlap = false;
	sampler.has_max_jaccard_overlap = false;
	sampler.max_sample = 1;
	sampler.max_trials = 1;
	batch_samplers.push_back(sampler);

	BatchSampler sampler1;
	memset(&sampler1, 0, sizeof(BatchSampler));
	sampler1.min_scale = 0.3;
	sampler1.max_scale = 1.0;
	sampler1.min_aspect_ratio = 0.5;
	sampler1.max_aspect_ratio = 2.0;
	sampler1.min_jaccard_overlap = 0.1;
	sampler1.has_min_jaccard_overlap = true;
	sampler1.has_max_jaccard_overlap = false;
	sampler1.max_sample = 1;
	sampler1.max_trials = 50;
	batch_samplers.push_back(sampler1);

	BatchSampler sampler2;
	memset(&sampler2, 0, sizeof(BatchSampler));
	sampler2.min_scale = 0.3;
	sampler2.max_scale = 1.0;
	sampler2.min_aspect_ratio = 0.5;
	sampler2.max_aspect_ratio = 2.0;
	sampler2.min_jaccard_overlap = 0.3;
	sampler2.has_min_jaccard_overlap = true;
	sampler2.has_max_jaccard_overlap = false;
	sampler2.max_sample = 1;
	sampler2.max_trials = 50;
	batch_samplers.push_back(sampler2);

	BatchSampler sampler3;
	memset(&sampler3, 0, sizeof(BatchSampler));
	sampler3.min_scale = 0.3;
	sampler3.max_scale = 1.0;
	sampler3.min_aspect_ratio = 0.5;
	sampler3.max_aspect_ratio = 2.0;
	sampler3.min_jaccard_overlap = 0.5;
	sampler3.has_min_jaccard_overlap = true;
	sampler3.has_max_jaccard_overlap = false;
	sampler3.max_sample = 1;
	sampler3.max_trials = 50;
	batch_samplers.push_back(sampler3);

	BatchSampler sampler4;
	memset(&sampler4, 0, sizeof(BatchSampler));
	sampler4.min_scale = 0.3;
	sampler4.max_scale = 1.0;
	sampler4.min_aspect_ratio = 0.5;
	sampler4.max_aspect_ratio = 2.0;
	sampler4.min_jaccard_overlap = 0.7;
	sampler4.has_min_jaccard_overlap = true;
	sampler4.has_max_jaccard_overlap = false;
	sampler4.max_sample = 1;
	sampler4.max_trials = 50;
	batch_samplers.push_back(sampler4);

	BatchSampler sampler5;
	memset(&sampler5, 0, sizeof(BatchSampler));
	sampler5.min_scale = 0.3;
	sampler5.max_scale = 1.0;
	sampler5.min_aspect_ratio = 0.5;
	sampler5.max_aspect_ratio = 2.0;
	sampler5.min_jaccard_overlap = 0.9;
	sampler5.has_min_jaccard_overlap = true;
	sampler5.has_max_jaccard_overlap = false;
	sampler5.max_sample = 1;
	sampler5.max_trials = 50;
	batch_samplers.push_back(sampler5);

	BatchSampler sampler6;
	memset(&sampler6, 0, sizeof(BatchSampler));
	sampler6.min_scale = 0.3;
	sampler6.max_scale = 1.0;
	sampler6.min_aspect_ratio = 0.5;
	sampler6.max_aspect_ratio = 2.0;
	sampler6.max_jaccard_overlap = 1.0;
	sampler6.has_min_jaccard_overlap = true;
	sampler6.has_max_jaccard_overlap = false;
	sampler6.max_sample = 1;
	sampler6.max_trials = 50;
	batch_samplers.push_back(sampler6);
}
int test58(int argc, char *argv[])
{

	string inputPath = "I:\\mtcnn-train\\rotate";
	string outputPath = "I:\\mtcnn-train\\rotateResult";
	mkdir(outputPath.c_str());
	string outputsrc = "I:\\mtcnn-train\\rotateResult\\src";
	mkdir(outputsrc.c_str());
	string outputtxt = "I:\\mtcnn-train\\rotateResult\\src\\000_one.txt";

	string outputdraw = "I:\\mtcnn-train\\rotateResult\\draw";
	mkdir(outputdraw.c_str());

	fstream finWrite;
	finWrite.open(outputtxt, ios::out);
	if (!finWrite.is_open())
	{
		cout << "finRead 文件数据打开错误！" << endl;
		system("pause");
		return false;
	}

	
	vector<string> v_img_;
	readDir((char*)inputPath.c_str(), v_img_);
	srand((unsigned)time(NULL));

	DistortParam distort_param;

	distort_param.brightness_prob = 0.5;
	distort_param.brightness_delta = 32;
	distort_param.contrast_prob = 0.5;
	distort_param.contrast_lower = 0.5;
	distort_param.contrast_upper = 1.5;
	distort_param.hue_prob = 0.5;
	distort_param.hue_delta = 18;
	distort_param.saturation_prob = 0.5;
	distort_param.saturation_lower = 0.5;
	distort_param.saturation_upper = 1.5;
	distort_param.random_order_prob = 0.0;

	ExpandParam expand_param;
	expand_param.expand_prob = 0.5;
	expand_param.max_expand_ratio = 4.0;

	vector<BatchSampler> batch_samplers;
	initBatchSampler(batch_samplers);
	
	/*bool has_min_sample_coverage = true;
	bool has_max_sample_coverage = true;
	float min_sample_coverage = 0;
	float max_sample_coverage = 0;*/
	/*bool has_min_object_coverage = true;
	bool has_max_object_coverage = true;
	float min_object_coverage = 0;
	float max_object_coverage = 0;*/


	for (int i = 0; i < v_img_.size(); i++)
	{
		cout << v_img_[i] << endl;
		int npos = v_img_[i].find_last_of('/');
		int npos2 = v_img_[i].find_last_of('.');
		string name1 = v_img_[i].substr(npos + 1, npos2 - npos - 1);
		Mat img = imread(v_img_[i].c_str());
		if (img.data == NULL)
		{

			printf("图像为空!\n");
			cout << v_img_[i].c_str() << endl;
			system("pause");
		}
		string nametxt = v_img_[i];
		nametxt.replace(nametxt.find_last_of("."), 4, ".txt");

		fstream fin1;
		fin1.open(nametxt);
		if (!fin1.is_open())
		{
			cout << "fin1 文件数据打开错误！" << endl;
			system("pause");
			continue;
		}

		int label; int x1, y1, x2, y2;

		fin1 >> label >> x1 >> y1 >> x2 >> y2;

		fin1.close();

		NormalizedBBox srcBox;
		memset(&srcBox, 0, sizeof(srcBox));
		srcBox.xmin = x1*1.0 / img.cols;
		srcBox.ymin = y1*1.0 / img.rows;
		srcBox.xmax = x2*1.0 / img.cols;
		srcBox.ymax = y2*1.0 / img.rows;
		srcBox.size = (srcBox.xmax - srcBox.xmin)*(srcBox.ymax - srcBox.ymin);
		
	
		
		{
			
			imwrite("1src.jpg",img);
			

			Mat dst = img.clone();
			
			imwrite("2dst.jpg", dst);
			
			RNGResult  rng_result;
			memset(&rng_result,0,sizeof(rng_result));
			DistortImage(img, distort_param, dst,  rng_result);

			imwrite("3dst.jpg", dst);
			
			cv::Mat out_img = img.clone();
			NoiseParameter param = {0};
			ApplyNoise(img,  out_img,  param);


			NormalizedBBox  expand_bbox;
			memset(&expand_bbox, 0, sizeof(expand_bbox));
			NormalizedBBox  projBox;
			memset(&projBox, 0, sizeof(projBox));
			Mat dst1 = dst.clone();
			int flag = ExpandImage1(dst, srcBox, expand_param, dst1, expand_bbox, projBox,rng_result);

			if (!flag)
			{
				printf("projBox 为空!\n");
				system("pause");
			}
			Point pt1, pt2;
			pt1.x = dst1.cols*projBox.xmin; pt1.y = dst1.rows*projBox.ymin;
			pt2.x = dst1.cols*projBox.xmax; pt2.y = dst1.rows*projBox.ymax;

			Mat dst1_temp = dst1.clone();
			rectangle(dst1_temp, pt1, pt2, Scalar(0, 0, 255));
			imwrite("4dst.jpg", dst1_temp);

			


			vector<NormalizedBBox> sampled_bboxes;
			
			//GenerateBatchSamples(dst1, srcBox, batch_samplers, sampled_bboxes);
			GenerateBatchSamples(dst1, projBox, batch_samplers, sampled_bboxes);
			
			dst1_temp = dst1.clone();
			for (int k = 0; k < sampled_bboxes.size();k++)
			{
				NormalizedBBox sample_bbox = sampled_bboxes[k];
				pt1.x = MAX(dst1.cols*sample_bbox.xmin, 0); pt1.y = MAX(dst1.rows*sample_bbox.ymin, 0);
				pt2.x = MIN(dst1.cols*sample_bbox.xmax, dst1.cols - 1); pt2.y = MIN(dst1.rows*sample_bbox.ymax, dst1.rows - 1);

				
				rectangle(dst1_temp, pt1, pt2, Scalar(0, 0, 255));
			}
			
			imwrite("5dst.jpg", dst1_temp);

			//system("pause");


			Mat dst2=dst1.clone();// (dst.size(), dst.type());

			

			for (int k = 0; k < sampled_bboxes.size(); k++)
			{

			

				NormalizedBBox  crop_bbox2;
				memset(&crop_bbox2, 0, sizeof(crop_bbox2));
				NormalizedBBox  proj_bbox;
				memset(&proj_bbox, 0, sizeof(proj_bbox));

				CropImage1(dst1, sampled_bboxes[k], dst2, srcBox, crop_bbox2, proj_bbox);



				pt1.x = MAX(dst2.cols*proj_bbox.xmin, 0); pt1.y = MAX(dst2.rows*proj_bbox.ymin, 0);
				pt2.x = MIN(dst2.cols*proj_bbox.xmax, dst2.cols - 1); pt2.y = MIN(dst2.rows*proj_bbox.ymax, dst2.rows - 1);

				Mat dst2_temp = dst2.clone();
				rectangle(dst2_temp, pt1, pt2, Scalar(0, 0, 255));

				char save1[256];
				sprintf(save1,"6dst-%d.jpg",k);
				imwrite(save1, dst2_temp);




				rng_result;
				/*char intstr[1024];
				sprintf(intstr, "-b%0.2f-c%0.2f-h%0.2f-s%0.2f-d%0.2f",rng_result.bright_delta,
					rng_result.contrast_delta, rng_result.hue_delta, rng_result.saturation_delta,
					rng_result.distort_prob);*/

				char intstr[1024];
				sprintf(intstr, "-b%0.2f", rng_result.bright_delta);


				string str1 = outputsrc + "/" + name1 + intstr + ".jpg";
				imwrite(str1.c_str(), dst2);

				int left = 0, top = 0, right = 0, bottom = 0;

				finWrite << label << " " << proj_bbox.xmin << " " << proj_bbox .ymin<< " " 
					<< proj_bbox.xmax << " " << proj_bbox.ymax << endl;

				CvPoint pt3, pt4;
				Mat drawimg = dst2.clone();

				rectangle(drawimg, pt3, pt4, Scalar(0, 0, 255));



				string str2 = outputdraw + "/" + name1 + intstr + ".jpg";
				imwrite(str2.c_str(), drawimg);

			}



			

			
		}


		int jj = 90;

	}

	finWrite.close();

	return 0;
}





