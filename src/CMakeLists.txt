add_library(Minuit2Base STATIC)

target_include_directories(Minuit2Base PUBLIC
						   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../inc>
						   $<INSTALL_INTERFACE:include> )

target_sources(Minuit2Base PUBLIC
         AnalyticalGradientCalculator.cxx	
         BasicMinimumError.cxx			
         CombinedMinimumBuilder.cxx		
         DavidonErrorUpdator.cxx		
         FumiliBuilder.cxx
         FumiliErrorUpdator.cxx
         FumiliGradientCalculator.cxx
         FumiliMinimizer.cxx
         FumiliStandardChi2FCN.cxx
	 FumiliStandardMaximumLikelihoodFCN.cxx
         HessianGradientCalculator.cxx		
         InitialGradientCalculator.cxx		
         LaEigenValues.cxx			
         LaInnerProduct.cxx			
         LaInverse.cxx				
         LaOuterProduct.cxx			
         LaSumOfElements.cxx			
         LaVtMVSimilarity.cxx			
         MnApplication.cxx			
         MnContours.cxx				
         MnCovarianceSqueeze.cxx		
         MnEigen.cxx				
         MnFcn.cxx				
         MnFunctionCross.cxx			
         MnFumiliMinimize.cxx			
         MnGlobalCorrelationCoeff.cxx		
         MnHesse.cxx				
         MnLineSearch.cxx			
         MnMachinePrecision.cxx			
         MnMinos.cxx				
         MnParabolaFactory.cxx			
         MnParameterScan.cxx			
         MnPlot.cxx				
         MnPosDef.cxx				
         MnPrint.cxx				
         MnScan.cxx				
         MnSeedGenerator.cxx			
         MnStrategy.cxx				
         MnTiny.cxx				
         MnUserFcn.cxx				
         MnUserParameterState.cxx		
         MnUserParameters.cxx			
         MnUserTransformation.cxx		
         ModularFunctionMinimizer.cxx		
         MPIProcess.cxx
         NegativeG2LineSearch.cxx		
         Numerical2PGradientCalculator.cxx	
         ParametricFunction.cxx
         ScanBuilder.cxx			
         SimplexBuilder.cxx			
         SimplexParameters.cxx			
         SimplexSeedGenerator.cxx		
         SinParameterTransformation.cxx		
         SqrtLowParameterTransformation.cxx	
         SqrtUpParameterTransformation.cxx	
         VariableMetricBuilder.cxx		
         VariableMetricEDMEstimator.cxx		
         mnbins.cxx				
         mndasum.cxx				
         mndaxpy.cxx				
         mnddot.cxx				
         mndscal.cxx				
         mndspmv.cxx				
         mndspr.cxx				
         mnteigen.cxx				
         mnlsame.cxx				
	 mntplot.cxx				
	 mnvert.cxx
         mnxerbla.cxx
)

install(TARGETS Minuit2Base
   ARCHIVE DESTINATION lib
   LIBRARY DESTINATION lib
   RUNTIME DESTINATION bin
   INCLUDES DESTINATION include
)
